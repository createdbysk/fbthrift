/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.patch;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial" })
public class MyDataWithCustomDefaultFieldPatch implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("MyDataWithCustomDefaultFieldPatch");
  private static final TField DATA1_FIELD_DESC = new TField("data1", TType.STRUCT, (short)1);
  private static final TField DATA2_FIELD_DESC = new TField("data2", TType.STRUCT, (short)2);

  public final StringPatch data1;
  public final I32Patch data2;
  public static final int DATA1 = 1;
  public static final int DATA2 = 2;

  public MyDataWithCustomDefaultFieldPatch(
      StringPatch data1,
      I32Patch data2) {
    this.data1 = data1;
    this.data2 = data2;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public MyDataWithCustomDefaultFieldPatch(MyDataWithCustomDefaultFieldPatch other) {
    if (other.isSetData1()) {
      this.data1 = TBaseHelper.deepCopy(other.data1);
    } else {
      this.data1 = null;
    }
    if (other.isSetData2()) {
      this.data2 = TBaseHelper.deepCopy(other.data2);
    } else {
      this.data2 = null;
    }
  }

  public MyDataWithCustomDefaultFieldPatch deepCopy() {
    return new MyDataWithCustomDefaultFieldPatch(this);
  }

  public StringPatch getData1() {
    return this.data1;
  }

  // Returns true if field data1 is set (has been assigned a value) and false otherwise
  public boolean isSetData1() {
    return this.data1 != null;
  }

  public I32Patch getData2() {
    return this.data2;
  }

  // Returns true if field data2 is set (has been assigned a value) and false otherwise
  public boolean isSetData2() {
    return this.data2 != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof MyDataWithCustomDefaultFieldPatch))
      return false;
    MyDataWithCustomDefaultFieldPatch that = (MyDataWithCustomDefaultFieldPatch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetData1(), that.isSetData1(), this.data1, that.data1)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetData2(), that.isSetData2(), this.data2, that.data2)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {data1, data2});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static MyDataWithCustomDefaultFieldPatch deserialize(TProtocol iprot) throws TException {
    StringPatch tmp_data1 = null;
    I32Patch tmp_data2 = null;
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case DATA1:
          if (__field.type == TType.STRUCT) {
            tmp_data1 = StringPatch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case DATA2:
          if (__field.type == TType.STRUCT) {
            tmp_data2 = I32Patch.deserialize(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();

    MyDataWithCustomDefaultFieldPatch _that;
    _that = new MyDataWithCustomDefaultFieldPatch(
      tmp_data1
      ,tmp_data2
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.data1 != null) {
      oprot.writeFieldBegin(DATA1_FIELD_DESC);
      this.data1.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.data2 != null) {
      oprot.writeFieldBegin(DATA2_FIELD_DESC);
      this.data2.write(oprot);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}
