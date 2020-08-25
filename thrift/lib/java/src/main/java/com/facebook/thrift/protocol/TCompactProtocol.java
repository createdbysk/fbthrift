/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.facebook.thrift.protocol;

import com.facebook.thrift.ShortStack;
import com.facebook.thrift.TException;
import com.facebook.thrift.transport.TTransport;
import com.facebook.thrift.utils.StandardCharsets;
import java.util.Map;

/**
 * TCompactProtocol2 is the Java implementation of the compact protocol specified in THRIFT-110. The
 * fundamental approach to reducing the overhead of structures is a) use variable-length integers
 * all over the place and b) make use of unused bits wherever possible. Your savings will obviously
 * vary based on the specific makeup of your structs, but in general, the more fields, nested
 * structures, short strings and collections, and low-value i32 and i64 fields you have, the more
 * benefit you'll see.
 */
public class TCompactProtocol extends TProtocol {

  private static final long NO_LENGTH_LIMIT = -1;

  private static final TStruct ANONYMOUS_STRUCT = new TStruct("");
  private static final TField TSTOP = new TField("", TType.STOP, (short) 0);

  private static final byte[] ttypeToCompactType = new byte[20];

  static {
    ttypeToCompactType[TType.STOP] = TType.STOP;
    ttypeToCompactType[TType.BOOL] = Types.BOOLEAN_TRUE;
    ttypeToCompactType[TType.BYTE] = Types.BYTE;
    ttypeToCompactType[TType.I16] = Types.I16;
    ttypeToCompactType[TType.I32] = Types.I32;
    ttypeToCompactType[TType.I64] = Types.I64;
    ttypeToCompactType[TType.DOUBLE] = Types.DOUBLE;
    ttypeToCompactType[TType.STRING] = Types.BINARY;
    ttypeToCompactType[TType.LIST] = Types.LIST;
    ttypeToCompactType[TType.SET] = Types.SET;
    ttypeToCompactType[TType.MAP] = Types.MAP;
    ttypeToCompactType[TType.STRUCT] = Types.STRUCT;
    ttypeToCompactType[TType.FLOAT] = Types.FLOAT;
  }

  /** TProtocolFactory that produces TCompactProtocols. */
  @SuppressWarnings("serial")
  public static class Factory implements TProtocolFactory {
    private final long stringLengthLimit_;
    private final long containerLengthLimit_;

    public Factory() {
      this(NO_LENGTH_LIMIT, NO_LENGTH_LIMIT);
    }

    public Factory(long stringLengthLimit) {
      this(stringLengthLimit, NO_LENGTH_LIMIT);
    }

    public Factory(long stringLengthLimit, long containerLengthLimit) {
      this.containerLengthLimit_ = containerLengthLimit;
      this.stringLengthLimit_ = stringLengthLimit;
    }

    public TProtocol getProtocol(TTransport trans) {
      return new TCompactProtocol(trans, stringLengthLimit_, containerLengthLimit_);
    }
  }

  public static final byte PROTOCOL_ID = (byte) 0x82;
  public static final int TYPE_SHIFT_AMOUNT = 5;
  private static final byte VERSION = 2;
  private static final byte VERSION_LOW = 1;
  private static final byte VERSION_DOUBLE_BE = 2;
  private static final byte VERSION_MASK = 0x1f; // 0001 1111
  private static final byte TYPE_MASK = (byte) 0xE0; // 1110 0000
  private static final byte TYPE_BITS = 0b0000_0111;

  /** All of the on-wire type codes. */
  private static class Types {
    public static final byte BOOLEAN_TRUE = 0x01;
    public static final byte BOOLEAN_FALSE = 0x02;
    public static final byte BYTE = 0x03;
    public static final byte I16 = 0x04;
    public static final byte I32 = 0x05;
    public static final byte I64 = 0x06;
    public static final byte DOUBLE = 0x07;
    public static final byte BINARY = 0x08;
    public static final byte LIST = 0x09;
    public static final byte SET = 0x0A;
    public static final byte MAP = 0x0B;
    public static final byte STRUCT = 0x0C;
    public static final byte FLOAT = 0x0D;
  }

  /**
   * Used to keep track of the last field for the current and previous structs, so we can do the
   * delta stuff.
   */
  private ShortStack lastField_ = new ShortStack(15);

  private short lastFieldId_ = 0;

  private byte version_ = VERSION;

  /**
   * If we encounter a boolean field begin, save the TField here so it can have the value
   * incorporated.
   */
  private TField booleanField_ = null;

  /**
   * If we read a field header, and it's a boolean field, save the boolean value here so that
   * readBool can use it.
   */
  private Boolean boolValue_ = null;

  /**
   * The maximum number of bytes to read from the transport for variable-length fields (such as
   * strings or binary) or {@link #NO_LENGTH_LIMIT} for unlimited.
   */
  private final long stringLengthLimit_;

  /**
   * The maximum number of elements to read from the network for containers (maps, sets, lists), or
   * {@link #NO_LENGTH_LIMIT} for unlimited.
   */
  private final long containerLengthLimit_;

  /** Temporary buffer to avoid allocations */
  private final byte[] buffer = new byte[10];

  /**
   * Create a TCompactProtocol.
   *
   * @param transport the TTransport object to read from or write to.
   * @param stringLengthLimit the maximum number of bytes to read for variable-length fields. If the
   *     value is <= 0, then the check is disable.
   * @param containerLengthLimit the maximum number of elements to read for containers. If the value
   *     is <= 0, then the check is disable.
   */
  public TCompactProtocol(TTransport transport, long stringLengthLimit, long containerLengthLimit) {
    super(transport);
    this.stringLengthLimit_ = stringLengthLimit;
    this.containerLengthLimit_ = containerLengthLimit;
  }

  /**
   * Create a TCompactProtocol.
   *
   * @param transport the TTransport object to read from or write to.
   */
  public TCompactProtocol(TTransport transport) {
    this(transport, NO_LENGTH_LIMIT, NO_LENGTH_LIMIT);
  }

  @Override
  public void reset() {
    lastField_.clear();
    lastFieldId_ = 0;
  }

  //
  // Public Writing methods.
  //

  /**
   * Write a message header to the wire. Compact Protocol messages contain the protocol version so
   * we can migrate forwards in the future if need be.
   */
  @Override
  public void writeMessageBegin(TMessage message) throws TException {
    writeByteDirect(PROTOCOL_ID);
    writeByteDirect((VERSION & VERSION_MASK) | ((message.type << TYPE_SHIFT_AMOUNT) & TYPE_MASK));
    writeVarint32(message.seqid);
    writeString(message.name);
  }

  /**
   * Write a struct begin. This doesn't actually put anything on the wire. We use it as an
   * opportunity to put special placeholder markers on the field stack so we can get the field id
   * deltas correct.
   */
  @Override
  public void writeStructBegin(TStruct struct) throws TException {
    lastField_.push(lastFieldId_);
    lastFieldId_ = 0;
  }

  /**
   * Write a struct end. This doesn't actually put anything on the wire. We use this as an
   * opportunity to pop the last field from the current struct off of the field stack.
   */
  @Override
  public void writeStructEnd() throws TException {
    lastFieldId_ = lastField_.pop();
  }

  /**
   * Write a field header containing the field id and field type. If the difference between the
   * current field id and the last one is small (< 15), then the field id will be encoded in the 4
   * MSB as a delta. Otherwise, the field id will follow the type header as a zigzag varint.
   */
  @Override
  public void writeFieldBegin(TField field) throws TException {
    if (field.type == TType.BOOL) {
      // we want to possibly include the value, so we'll wait.
      booleanField_ = field;
    } else {
      writeFieldBeginInternal(field, (byte) -1);
    }
  }

  /**
   * The workhorse of writeFieldBegin. It has the option of doing a 'type override' of the type
   * header. This is used specifically in the boolean field case.
   */
  private void writeFieldBeginInternal(TField field, byte typeOverride) throws TException {
    // short lastField = lastField_.pop();

    // if there's a type override, use that.
    byte typeToWrite = typeOverride == -1 ? getCompactType(field.type) : typeOverride;

    // check if we can use delta encoding for the field id
    if (field.id > lastFieldId_ && field.id - lastFieldId_ <= 15) {
      // write them together
      writeByteDirect((field.id - lastFieldId_) << 4 | typeToWrite);
    } else {
      // write them separate
      writeByteDirect(typeToWrite);
      writeI16(field.id);
    }

    lastFieldId_ = field.id;
    // lastField_.push(field.id);
  }

  /** Write the STOP symbol so we know there are no more fields in this struct. */
  @Override
  public void writeFieldStop() throws TException {
    writeByteDirect(TType.STOP);
  }

  /**
   * Write a map header. If the map is empty, omit the key and value type headers, as we don't need
   * any additional information to skip it.
   */
  @Override
  public void writeMapBegin(TMap map) throws TException {
    if (map.size == 0) {
      writeByteDirect(0);
    } else {
      writeVarint32(map.size);
      writeByteDirect(getCompactType(map.keyType) << 4 | getCompactType(map.valueType));
    }
  }

  /** Write a list header. */
  @Override
  public void writeListBegin(TList list) throws TException {
    writeCollectionBegin(list.elemType, list.size);
  }

  /** Write a set header. */
  @Override
  public void writeSetBegin(TSet set) throws TException {
    writeCollectionBegin(set.elemType, set.size);
  }

  /**
   * Write a boolean value. Potentially, this could be a boolean field, in which case the field
   * header info isn't written yet. If so, decide what the right type header is for the value and
   * then write the field header. Otherwise, write a single byte.
   */
  @Override
  public void writeBool(boolean b) throws TException {
    if (booleanField_ != null) {
      // we haven't written the field header yet
      writeFieldBeginInternal(booleanField_, b ? Types.BOOLEAN_TRUE : Types.BOOLEAN_FALSE);
      booleanField_ = null;
    } else {
      // we're not part of a field, so just write the value.
      writeByteDirect(b ? Types.BOOLEAN_TRUE : Types.BOOLEAN_FALSE);
    }
  }

  /** Write a byte. Nothing to see here! */
  @Override
  public void writeByte(byte b) throws TException {
    writeByteDirect(b);
  }

  /** Write an I16 as a zigzag varint. */
  @Override
  public void writeI16(short i16) throws TException {
    writeVarint32(intToZigZag(i16));
  }

  /** Write an i32 as a zigzag varint. */
  @Override
  public void writeI32(int i32) throws TException {
    writeVarint32(intToZigZag(i32));
  }

  /** Write an i64 as a zigzag varint. */
  @Override
  public void writeI64(long i64) throws TException {
    writeVarint64(longToZigzag(i64));
  }

  /** Write a double to the wire as 8 bytes. */
  @Override
  public void writeDouble(double dub) throws TException {
    fixedLongToBytes(Double.doubleToLongBits(dub), buffer, 0);
    trans_.write(buffer, 0, 8);
  }

  /** Write a float to the wire as 4 bytes. */
  @Override
  public void writeFloat(float flt) throws TException {
    fixedIntToBytes(Float.floatToIntBits(flt), buffer, 0);
    trans_.write(buffer, 0, 4);
  }

  /** Write a string to the wire with a varint size preceding. */
  @Override
  public void writeString(String str) throws TException {
    byte[] bytes = str.getBytes(StandardCharsets.UTF_8);
    writeBinary(bytes, 0, bytes.length);
  }

  /** Write a byte array, using a varint for the size. */
  @Override
  public void writeBinary(byte[] buf) throws TException {
    writeBinary(buf, 0, buf.length);
  }

  private void writeBinary(byte[] buf, int offset, int length) throws TException {
    writeVarint32(length);
    trans_.write(buf, offset, length);
  }

  //
  // These methods are called by structs, but don't actually have any wire
  // output or purpose.
  //

  @Override
  public void writeMessageEnd() throws TException {}

  @Override
  public void writeMapEnd() throws TException {}

  @Override
  public void writeListEnd() throws TException {}

  @Override
  public void writeSetEnd() throws TException {}

  @Override
  public void writeFieldEnd() throws TException {}

  //
  // Internal writing methods
  //

  /**
   * Abstract method for writing the start of lists and sets. List and sets on the wire differ only
   * by the type indicator.
   */
  protected void writeCollectionBegin(byte elemType, int size) throws TException {
    if (size <= 14) {
      writeByteDirect(size << 4 | getCompactType(elemType));
    } else {
      writeByteDirect(0xf0 | getCompactType(elemType));
      writeVarint32(size);
    }
  }

  /** Write an i32 as a varint. Results in 1-5 bytes on the wire. */
  private void writeVarint32(int n) throws TException {
    int idx = 0;
    while (true) {
      if ((n & ~0x7F) == 0) {
        buffer[idx++] = (byte) n;
        break;
      } else {
        buffer[idx++] = (byte) ((n & 0x7F) | 0x80);
        n >>>= 7;
      }
    }
    trans_.write(buffer, 0, idx);
  }

  /** Write an i64 as a varint. Results in 1-10 bytes on the wire. */
  private void writeVarint64(long n) throws TException {
    int idx = 0;
    while (true) {
      if ((n & ~0x7FL) == 0) {
        buffer[idx++] = (byte) n;
        break;
      } else {
        buffer[idx++] = ((byte) ((n & 0x7F) | 0x80));
        n >>>= 7;
      }
    }
    trans_.write(buffer, 0, idx);
  }

  /**
   * Convert l into a zigzag long. This allows negative numbers to be represented compactly as a
   * varint.
   */
  private long longToZigzag(long l) {
    return (l << 1) ^ (l >> 63);
  }

  /**
   * Convert n into a zigzag int. This allows negative numbers to be represented compactly as a
   * varint.
   */
  private int intToZigZag(int n) {
    return (n << 1) ^ (n >> 31);
  }

  /** Convert a long into little-endian bytes in buf starting at off and going until off+7. */
  private void fixedLongToBytes(long n, byte[] buf, int off) {
    buf[off + 0] = (byte) ((n >> 56) & 0xff);
    buf[off + 1] = (byte) ((n >> 48) & 0xff);
    buf[off + 2] = (byte) ((n >> 40) & 0xff);
    buf[off + 3] = (byte) ((n >> 32) & 0xff);
    buf[off + 4] = (byte) ((n >> 24) & 0xff);
    buf[off + 5] = (byte) ((n >> 16) & 0xff);
    buf[off + 6] = (byte) ((n >> 8) & 0xff);
    buf[off + 7] = (byte) (n & 0xff);
  }

  /** Convert a long into little-endian bytes in buf starting at off and going until off+7. */
  private void fixedIntToBytes(int n, byte[] buf, int off) {
    buf[off + 0] = (byte) ((n >> 24) & 0xff);
    buf[off + 1] = (byte) ((n >> 16) & 0xff);
    buf[off + 2] = (byte) ((n >> 8) & 0xff);
    buf[off + 3] = (byte) (n & 0xff);
  }

  /**
   * Writes a byte without any possiblity of all that field header nonsense. Used internally by
   * other writing methods that know they need to write a byte.
   */
  private void writeByteDirect(byte b) throws TException {
    buffer[0] = b;
    trans_.write(buffer, 0, 1);
  }

  /** Writes a byte without any possiblity of all that field header nonsense. */
  private void writeByteDirect(int n) throws TException {
    writeByteDirect((byte) n);
  }

  //
  // Reading methods.
  //

  /** Read a message header. */
  @Override
  public TMessage readMessageBegin() throws TException {
    byte protocolId = readByte();
    if (protocolId != PROTOCOL_ID) {
      throw new TProtocolException(
          "Expected protocol id "
              + Integer.toHexString(PROTOCOL_ID)
              + " but got "
              + Integer.toHexString(protocolId));
    }
    byte versionAndType = readByte();
    version_ = (byte) (versionAndType & VERSION_MASK);
    if (!(version_ <= VERSION && version_ >= VERSION_LOW)) {
      throw new TProtocolException("Expected version " + VERSION + " but got " + version_);
    }
    byte type = (byte) ((versionAndType >> TYPE_SHIFT_AMOUNT) & TYPE_BITS);
    int seqid = readVarint32();
    String messageName = readString();
    return new TMessage(messageName, type, seqid);
  }

  /**
   * Read a struct begin. There's nothing on the wire for this, but it is our opportunity to push a
   * new struct begin marker onto the field stack.
   */
  public TStruct readStructBegin(
      Map<Integer, com.facebook.thrift.meta_data.FieldMetaData> metaDataMap) throws TException {
    lastField_.push(lastFieldId_);
    lastFieldId_ = 0;
    return ANONYMOUS_STRUCT;
  }

  /**
   * Doesn't actually consume any wire data, just removes the last field for this struct from the
   * field stack.
   */
  @Override
  public void readStructEnd() throws TException {
    // consume the last field we read off the wire.
    lastFieldId_ = lastField_.pop();
  }

  /** Read a field header off the wire. */
  @Override
  public TField readFieldBegin() throws TException {
    byte type = readByte();

    // if it's a stop, then we can return immediately, as the struct is over.
    if (type == TType.STOP) {
      return TSTOP;
    }

    short fieldId;

    // mask off the 4 MSB of the type header. it could contain a field id delta.
    short modifier = (short) ((type & 0xf0) >> 4);
    if (modifier == 0) {
      // not a delta. look ahead for the zigzag varint field id.
      fieldId = readI16();
    } else {
      // has a delta. add the delta to the last read field id.
      fieldId = (short) (lastFieldId_ + modifier);
    }

    TField field = new TField("", getTType((byte) (type & 0x0f)), fieldId);

    // if this happens to be a boolean field, the value is encoded in the type
    if (isBoolType(type)) {
      // save the boolean value in a special instance variable.
      boolValue_ = (byte) (type & 0x0f) == Types.BOOLEAN_TRUE ? Boolean.TRUE : Boolean.FALSE;
    }

    // push the new field onto the field stack so we can keep the deltas going.
    lastFieldId_ = field.id;
    return field;
  }

  /**
   * Read a map header off the wire. If the size is zero, skip reading the key and value type. This
   * means that 0-length maps will yield TMaps without the "correct" types.
   */
  @Override
  public TMap readMapBegin() throws TException {
    int size = readVarint32();
    checkContainerReadLength(size);
    byte keyAndValueType = size == 0 ? 0 : readByte();
    byte keyType = getTType((byte) (keyAndValueType >> 4));
    byte valueType = getTType((byte) (keyAndValueType & 0xf));
    if (size > 0) {
      ensureMapHasEnough(size, keyType, valueType);
    }
    return new TMap(keyType, valueType, size);
  }

  /**
   * Read a list header off the wire. If the list size is 0-14, the size will be packed into the
   * element type header. If it's a longer list, the 4 MSB of the element type header will be 0xF,
   * and a varint will follow with the true size.
   */
  @Override
  public TList readListBegin() throws TException {
    byte size_and_type = readByte();
    int size = (size_and_type >> 4) & 0x0f;
    if (size == 15) {
      size = readVarint32();
    }
    checkContainerReadLength(size);
    byte type = getTType(size_and_type);
    ensureContainerHasEnough(size, type);
    return new TList(type, size);
  }

  /**
   * Read a set header off the wire. If the set size is 0-14, the size will be packed into the
   * element type header. If it's a longer set, the 4 MSB of the element type header will be 0xF,
   * and a varint will follow with the true size.
   */
  @Override
  public TSet readSetBegin() throws TException {
    return new TSet(readListBegin());
  }

  /**
   * Read a boolean off the wire. If this is a boolean field, the value should already have been
   * read during readFieldBegin, so we'll just consume the pre-stored value. Otherwise, read a byte.
   */
  @Override
  public boolean readBool() throws TException {
    if (boolValue_ != null) {
      boolean result = boolValue_.booleanValue();
      boolValue_ = null;
      return result;
    }
    return readByte() == Types.BOOLEAN_TRUE;
  }

  /** Read a single byte off the wire. Nothing interesting here. */
  @Override
  public byte readByte() throws TException {
    byte b;
    if (trans_.getBytesRemainingInBuffer() > 0) {
      b = trans_.getBuffer()[trans_.getBufferPosition()];
      trans_.consumeBuffer(1);
    } else {
      trans_.readAll(buffer, 0, 1);
      b = buffer[0];
    }
    return b;
  }

  /** Read an i16 from the wire as a zigzag varint. */
  @Override
  public short readI16() throws TException {
    return (short) zigzagToInt(readVarint32());
  }

  /** Read an i32 from the wire as a zigzag varint. */
  @Override
  public int readI32() throws TException {
    return zigzagToInt(readVarint32());
  }

  /** Read an i64 from the wire as a zigzag varint. */
  @Override
  public long readI64() throws TException {
    return zigzagToLong(readVarint64());
  }

  /** No magic here - just read a double off the wire. */
  @Override
  public double readDouble() throws TException {
    trans_.readAll(buffer, 0, 8);
    long value;
    if (version_ >= VERSION_DOUBLE_BE) {
      value = bytesToLong(buffer);
    } else {
      value = bytesToLongLE(buffer);
    }
    return Double.longBitsToDouble(value);
  }

  /** No magic here - just read a float off the wire. */
  @Override
  public float readFloat() throws TException {
    trans_.readAll(buffer, 0, 4);
    int value = bytesToInt(buffer);
    return Float.intBitsToFloat(value);
  }

  /** Reads a byte[] (via readBinary), and then UTF-8 decodes it. */
  @Override
  public String readString() throws TException {
    int length = readVarint32();
    checkContentReadLength(length);

    if (length == 0) {
      return "";
    }

    if (trans_.getBytesRemainingInBuffer() >= length) {
      String str =
          new String(
              trans_.getBuffer(), trans_.getBufferPosition(), length, StandardCharsets.UTF_8);
      trans_.consumeBuffer(length);
      return str;
    } else {
      return new String(readBinary(length), StandardCharsets.UTF_8);
    }
  }

  /** Read a byte[] from the wire. */
  @Override
  public byte[] readBinary() throws TException {
    int length = readVarint32();
    checkContentReadLength(length);
    return readBinary(length);
  }

  private byte[] readBinary(int length) throws TException {
    if (length == 0) {
      return new byte[0];
    }

    ensureContainerHasEnough(length, TType.BYTE);
    byte[] buf = new byte[length];
    trans_.readAll(buf, 0, length);
    return buf;
  }

  private void checkContentReadLength(int length) throws TProtocolException {
    if (length < 0) {
      throw new TProtocolException(TProtocolException.NEGATIVE_SIZE, "Negative length: " + length);
    }
    if (stringLengthLimit_ > 0 && length > stringLengthLimit_) {
      throw new TProtocolException(
          TProtocolException.SIZE_LIMIT,
          String.format(
              "String/binary length %s exceeded max allowed %s", length, stringLengthLimit_));
    }
  }

  private void checkContainerReadLength(int length) throws TProtocolException {
    if (length < 0) {
      throw new TProtocolException(TProtocolException.NEGATIVE_SIZE, "Negative length: " + length);
    }
    if (containerLengthLimit_ > 0 && length > containerLengthLimit_) {
      throw new TProtocolException(
          TProtocolException.SIZE_LIMIT,
          String.format(
              "Container length %s exceeded max allowed %s", length, containerLengthLimit_));
    }
  }

  //
  // These methods are here for the struct to call, but don't have any wire
  // encoding.
  //
  @Override
  public void readMessageEnd() throws TException {}

  @Override
  public void readFieldEnd() throws TException {}

  @Override
  public void readMapEnd() throws TException {}

  @Override
  public void readListEnd() throws TException {}

  @Override
  public void readSetEnd() throws TException {}

  //
  // Internal reading methods
  //

  /**
   * Read an i32 from the wire as a varint. The MSB of each byte is set if there is another byte to
   * follow. This can read up to 5 bytes.
   */
  private int readVarint32() throws TException {
    int result = 0;
    int shift = 0;
    if (trans_.getBytesRemainingInBuffer() >= 5) {
      byte[] buf = trans_.getBuffer();
      int pos = trans_.getBufferPosition();
      int off = 0;
      while (true) {
        byte b = buf[pos + off];
        result |= (int) (b & 0x7f) << shift;
        if ((b & 0x80) != 0x80) {
          break;
        }
        shift += 7;
        off++;
      }
      trans_.consumeBuffer(off + 1);
    } else {
      while (true) {
        byte b = readByte();
        result |= (int) (b & 0x7f) << shift;
        if ((b & 0x80) != 0x80) {
          break;
        }
        shift += 7;
      }
    }
    return result;
  }

  /**
   * Read an i64 from the wire as a proper varint. The MSB of each byte is set if there is another
   * byte to follow. This can read up to 10 bytes.
   */
  private long readVarint64() throws TException {
    int shift = 0;
    long result = 0;
    if (trans_.getBytesRemainingInBuffer() >= 10) {
      byte[] buf = trans_.getBuffer();
      int pos = trans_.getBufferPosition();
      int off = 0;
      while (true) {
        byte b = buf[pos + off];
        result |= (long) (b & 0x7f) << shift;
        if ((b & 0x80) != 0x80) {
          break;
        }
        shift += 7;
        off++;
      }
      trans_.consumeBuffer(off + 1);
    } else {
      while (true) {
        byte b = readByte();
        result |= (long) (b & 0x7f) << shift;
        if ((b & 0x80) != 0x80) {
          break;
        }
        shift += 7;
      }
    }
    return result;
  }

  //
  // encoding helpers
  //

  /** Convert from zigzag int to int. */
  private int zigzagToInt(int n) {
    return (n >>> 1) ^ -(n & 1);
  }

  /** Convert from zigzag long to long. */
  private long zigzagToLong(long n) {
    return (n >>> 1) ^ -(n & 1);
  }

  /**
   * Note that it's important that the mask bytes are long literals, otherwise they'll default to
   * ints, and when you shift an int left 56 bits, you just get a messed up int.
   */
  private long bytesToLong(byte[] bytes) {
    return ((bytes[0] & 0xffL) << 56)
        | ((bytes[1] & 0xffL) << 48)
        | ((bytes[2] & 0xffL) << 40)
        | ((bytes[3] & 0xffL) << 32)
        | ((bytes[4] & 0xffL) << 24)
        | ((bytes[5] & 0xffL) << 16)
        | ((bytes[6] & 0xffL) << 8)
        | ((bytes[7] & 0xffL));
  }

  /* Little endian version of the above */
  private long bytesToLongLE(byte[] bytes) {
    return ((bytes[7] & 0xffL) << 56)
        | ((bytes[6] & 0xffL) << 48)
        | ((bytes[5] & 0xffL) << 40)
        | ((bytes[4] & 0xffL) << 32)
        | ((bytes[3] & 0xffL) << 24)
        | ((bytes[2] & 0xffL) << 16)
        | ((bytes[1] & 0xffL) << 8)
        | ((bytes[0] & 0xffL));
  }

  private int bytesToInt(byte[] bytes) {
    return ((bytes[0] & 0xff) << 24)
        | ((bytes[1] & 0xff) << 16)
        | ((bytes[2] & 0xff) << 8)
        | ((bytes[3] & 0xff));
  }

  //
  // type testing and converting
  //

  private boolean isBoolType(byte b) {
    int lowerNibble = b & 0x0f;
    return lowerNibble == Types.BOOLEAN_TRUE || lowerNibble == Types.BOOLEAN_FALSE;
  }

  /** Given a TCompactProtocol.Types constant, convert it to its corresponding TType value. */
  private byte getTType(byte type) throws TProtocolException {
    switch ((byte) (type & 0x0f)) {
      case TType.STOP:
        return TType.STOP;
      case Types.BOOLEAN_FALSE:
      case Types.BOOLEAN_TRUE:
        return TType.BOOL;
      case Types.BYTE:
        return TType.BYTE;
      case Types.I16:
        return TType.I16;
      case Types.I32:
        return TType.I32;
      case Types.I64:
        return TType.I64;
      case Types.DOUBLE:
        return TType.DOUBLE;
      case Types.FLOAT:
        return TType.FLOAT;
      case Types.BINARY:
        return TType.STRING;
      case Types.LIST:
        return TType.LIST;
      case Types.SET:
        return TType.SET;
      case Types.MAP:
        return TType.MAP;
      case Types.STRUCT:
        return TType.STRUCT;
      default:
        throw new TProtocolException("don't know what type: " + (byte) (type & 0x0f));
    }
  }

  /** Given a TType value, find the appropriate TCompactProtocol.Types constant. */
  private byte getCompactType(byte ttype) {
    return ttypeToCompactType[ttype];
  }

  @Override
  protected int typeMinimumSize(byte type) {
    switch (type & 0x0f) {
      case TType.BOOL:
      case TType.BYTE:
      case TType.I16: // because of variable length encoding
      case TType.I32: // because of variable length encoding
      case TType.I64: // because of variable length encoding
      case TType.FLOAT: // because of variable length encoding
      case TType.DOUBLE: // because of variable length encoding
      case TType.STRING:
      case TType.STRUCT:
      case TType.MAP:
      case TType.SET:
      case TType.LIST:
      case TType.ENUM:
        return 1;
      default:
        throw new TProtocolException(
            TProtocolException.INVALID_DATA, "Unexpected data type " + (byte) (type & 0x0f));
    }
  }
}
