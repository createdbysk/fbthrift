/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.adapter;

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
public class AdaptTemplatedTestStruct implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("AdaptTemplatedTestStruct");
  private static final TField ADAPTED_BOOL_FIELD_DESC = new TField("adaptedBool", TType.BOOL, (short)1);
  private static final TField ADAPTED_BYTE_FIELD_DESC = new TField("adaptedByte", TType.BYTE, (short)2);
  private static final TField ADAPTED_SHORT_FIELD_DESC = new TField("adaptedShort", TType.I16, (short)3);
  private static final TField ADAPTED_INTEGER_FIELD_DESC = new TField("adaptedInteger", TType.I32, (short)4);
  private static final TField ADAPTED_LONG_FIELD_DESC = new TField("adaptedLong", TType.I64, (short)5);
  private static final TField ADAPTED_DOUBLE_FIELD_DESC = new TField("adaptedDouble", TType.DOUBLE, (short)6);
  private static final TField ADAPTED_STRING_FIELD_DESC = new TField("adaptedString", TType.STRING, (short)7);
  private static final TField ADAPTED_LIST_FIELD_DESC = new TField("adaptedList", TType.LIST, (short)8);
  private static final TField ADAPTED_SET_FIELD_DESC = new TField("adaptedSet", TType.SET, (short)9);
  private static final TField ADAPTED_MAP_FIELD_DESC = new TField("adaptedMap", TType.MAP, (short)10);
  private static final TField ADAPTED_BOOL_DEFAULT_FIELD_DESC = new TField("adaptedBoolDefault", TType.BOOL, (short)11);
  private static final TField ADAPTED_BYTE_DEFAULT_FIELD_DESC = new TField("adaptedByteDefault", TType.BYTE, (short)12);
  private static final TField ADAPTED_SHORT_DEFAULT_FIELD_DESC = new TField("adaptedShortDefault", TType.I16, (short)13);
  private static final TField ADAPTED_INTEGER_DEFAULT_FIELD_DESC = new TField("adaptedIntegerDefault", TType.I32, (short)14);
  private static final TField ADAPTED_LONG_DEFAULT_FIELD_DESC = new TField("adaptedLongDefault", TType.I64, (short)15);
  private static final TField ADAPTED_DOUBLE_DEFAULT_FIELD_DESC = new TField("adaptedDoubleDefault", TType.DOUBLE, (short)16);
  private static final TField ADAPTED_STRING_DEFAULT_FIELD_DESC = new TField("adaptedStringDefault", TType.STRING, (short)17);
  private static final TField ADAPTED_ENUM_FIELD_DESC = new TField("adaptedEnum", TType.I32, (short)18);
  private static final TField ADAPTED_LIST_DEFAULT_FIELD_DESC = new TField("adaptedListDefault", TType.LIST, (short)19);
  private static final TField ADAPTED_SET_DEFAULT_FIELD_DESC = new TField("adaptedSetDefault", TType.SET, (short)20);
  private static final TField ADAPTED_MAP_DEFAULT_FIELD_DESC = new TField("adaptedMapDefault", TType.MAP, (short)21);
  private static final TField DOUBLE_TYPEDEF_BOOL_FIELD_DESC = new TField("doubleTypedefBool", TType.BOOL, (short)22);

  public final Boolean adaptedBool;
  public final Byte adaptedByte;
  public final Short adaptedShort;
  public final Integer adaptedInteger;
  public final Long adaptedLong;
  public final Double adaptedDouble;
  public final String adaptedString;
  public final List<Long> adaptedList;
  public final Set<Long> adaptedSet;
  public final Map<Long,Long> adaptedMap;
  public final Boolean adaptedBoolDefault;
  public final Byte adaptedByteDefault;
  public final Short adaptedShortDefault;
  public final Integer adaptedIntegerDefault;
  public final Long adaptedLongDefault;
  public final Double adaptedDoubleDefault;
  public final String adaptedStringDefault;
  public final ThriftAdaptedEnum adaptedEnum;
  public final List<Long> adaptedListDefault;
  public final Set<Long> adaptedSetDefault;
  public final Map<Long,Long> adaptedMapDefault;
  public final Boolean doubleTypedefBool;
  public static final int ADAPTEDBOOL = 1;
  public static final int ADAPTEDBYTE = 2;
  public static final int ADAPTEDSHORT = 3;
  public static final int ADAPTEDINTEGER = 4;
  public static final int ADAPTEDLONG = 5;
  public static final int ADAPTEDDOUBLE = 6;
  public static final int ADAPTEDSTRING = 7;
  public static final int ADAPTEDLIST = 8;
  public static final int ADAPTEDSET = 9;
  public static final int ADAPTEDMAP = 10;
  public static final int ADAPTEDBOOLDEFAULT = 11;
  public static final int ADAPTEDBYTEDEFAULT = 12;
  public static final int ADAPTEDSHORTDEFAULT = 13;
  public static final int ADAPTEDINTEGERDEFAULT = 14;
  public static final int ADAPTEDLONGDEFAULT = 15;
  public static final int ADAPTEDDOUBLEDEFAULT = 16;
  public static final int ADAPTEDSTRINGDEFAULT = 17;
  public static final int ADAPTEDENUM = 18;
  public static final int ADAPTEDLISTDEFAULT = 19;
  public static final int ADAPTEDSETDEFAULT = 20;
  public static final int ADAPTEDMAPDEFAULT = 21;
  public static final int DOUBLETYPEDEFBOOL = 22;

  public AdaptTemplatedTestStruct(
      Boolean adaptedBool,
      Byte adaptedByte,
      Short adaptedShort,
      Integer adaptedInteger,
      Long adaptedLong,
      Double adaptedDouble,
      String adaptedString,
      List<Long> adaptedList,
      Set<Long> adaptedSet,
      Map<Long,Long> adaptedMap,
      Boolean adaptedBoolDefault,
      Byte adaptedByteDefault,
      Short adaptedShortDefault,
      Integer adaptedIntegerDefault,
      Long adaptedLongDefault,
      Double adaptedDoubleDefault,
      String adaptedStringDefault,
      ThriftAdaptedEnum adaptedEnum,
      List<Long> adaptedListDefault,
      Set<Long> adaptedSetDefault,
      Map<Long,Long> adaptedMapDefault,
      Boolean doubleTypedefBool) {
    this.adaptedBool = adaptedBool;
    this.adaptedByte = adaptedByte;
    this.adaptedShort = adaptedShort;
    this.adaptedInteger = adaptedInteger;
    this.adaptedLong = adaptedLong;
    this.adaptedDouble = adaptedDouble;
    this.adaptedString = adaptedString;
    this.adaptedList = adaptedList;
    this.adaptedSet = adaptedSet;
    this.adaptedMap = adaptedMap;
    this.adaptedBoolDefault = adaptedBoolDefault;
    this.adaptedByteDefault = adaptedByteDefault;
    this.adaptedShortDefault = adaptedShortDefault;
    this.adaptedIntegerDefault = adaptedIntegerDefault;
    this.adaptedLongDefault = adaptedLongDefault;
    this.adaptedDoubleDefault = adaptedDoubleDefault;
    this.adaptedStringDefault = adaptedStringDefault;
    this.adaptedEnum = adaptedEnum;
    this.adaptedListDefault = adaptedListDefault;
    this.adaptedSetDefault = adaptedSetDefault;
    this.adaptedMapDefault = adaptedMapDefault;
    this.doubleTypedefBool = doubleTypedefBool;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public AdaptTemplatedTestStruct(AdaptTemplatedTestStruct other) {
    if (other.isSetAdaptedBool()) {
      this.adaptedBool = TBaseHelper.deepCopy(other.adaptedBool);
    } else {
      this.adaptedBool = null;
    }
    if (other.isSetAdaptedByte()) {
      this.adaptedByte = TBaseHelper.deepCopy(other.adaptedByte);
    } else {
      this.adaptedByte = null;
    }
    if (other.isSetAdaptedShort()) {
      this.adaptedShort = TBaseHelper.deepCopy(other.adaptedShort);
    } else {
      this.adaptedShort = null;
    }
    if (other.isSetAdaptedInteger()) {
      this.adaptedInteger = TBaseHelper.deepCopy(other.adaptedInteger);
    } else {
      this.adaptedInteger = null;
    }
    if (other.isSetAdaptedLong()) {
      this.adaptedLong = TBaseHelper.deepCopy(other.adaptedLong);
    } else {
      this.adaptedLong = null;
    }
    if (other.isSetAdaptedDouble()) {
      this.adaptedDouble = TBaseHelper.deepCopy(other.adaptedDouble);
    } else {
      this.adaptedDouble = null;
    }
    if (other.isSetAdaptedString()) {
      this.adaptedString = TBaseHelper.deepCopy(other.adaptedString);
    } else {
      this.adaptedString = null;
    }
    if (other.isSetAdaptedList()) {
      this.adaptedList = TBaseHelper.deepCopy(other.adaptedList);
    } else {
      this.adaptedList = null;
    }
    if (other.isSetAdaptedSet()) {
      this.adaptedSet = TBaseHelper.deepCopy(other.adaptedSet);
    } else {
      this.adaptedSet = null;
    }
    if (other.isSetAdaptedMap()) {
      this.adaptedMap = TBaseHelper.deepCopy(other.adaptedMap);
    } else {
      this.adaptedMap = null;
    }
    if (other.isSetAdaptedBoolDefault()) {
      this.adaptedBoolDefault = TBaseHelper.deepCopy(other.adaptedBoolDefault);
    } else {
      this.adaptedBoolDefault = null;
    }
    if (other.isSetAdaptedByteDefault()) {
      this.adaptedByteDefault = TBaseHelper.deepCopy(other.adaptedByteDefault);
    } else {
      this.adaptedByteDefault = null;
    }
    if (other.isSetAdaptedShortDefault()) {
      this.adaptedShortDefault = TBaseHelper.deepCopy(other.adaptedShortDefault);
    } else {
      this.adaptedShortDefault = null;
    }
    if (other.isSetAdaptedIntegerDefault()) {
      this.adaptedIntegerDefault = TBaseHelper.deepCopy(other.adaptedIntegerDefault);
    } else {
      this.adaptedIntegerDefault = null;
    }
    if (other.isSetAdaptedLongDefault()) {
      this.adaptedLongDefault = TBaseHelper.deepCopy(other.adaptedLongDefault);
    } else {
      this.adaptedLongDefault = null;
    }
    if (other.isSetAdaptedDoubleDefault()) {
      this.adaptedDoubleDefault = TBaseHelper.deepCopy(other.adaptedDoubleDefault);
    } else {
      this.adaptedDoubleDefault = null;
    }
    if (other.isSetAdaptedStringDefault()) {
      this.adaptedStringDefault = TBaseHelper.deepCopy(other.adaptedStringDefault);
    } else {
      this.adaptedStringDefault = null;
    }
    if (other.isSetAdaptedEnum()) {
      this.adaptedEnum = TBaseHelper.deepCopy(other.adaptedEnum);
    } else {
      this.adaptedEnum = null;
    }
    if (other.isSetAdaptedListDefault()) {
      this.adaptedListDefault = TBaseHelper.deepCopy(other.adaptedListDefault);
    } else {
      this.adaptedListDefault = null;
    }
    if (other.isSetAdaptedSetDefault()) {
      this.adaptedSetDefault = TBaseHelper.deepCopy(other.adaptedSetDefault);
    } else {
      this.adaptedSetDefault = null;
    }
    if (other.isSetAdaptedMapDefault()) {
      this.adaptedMapDefault = TBaseHelper.deepCopy(other.adaptedMapDefault);
    } else {
      this.adaptedMapDefault = null;
    }
    if (other.isSetDoubleTypedefBool()) {
      this.doubleTypedefBool = TBaseHelper.deepCopy(other.doubleTypedefBool);
    } else {
      this.doubleTypedefBool = null;
    }
  }

  public AdaptTemplatedTestStruct deepCopy() {
    return new AdaptTemplatedTestStruct(this);
  }

  public Boolean isAdaptedBool() {
    return this.adaptedBool;
  }

  // Returns true if field adaptedBool is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedBool() {
    return this.adaptedBool != null;
  }

  public Byte getAdaptedByte() {
    return this.adaptedByte;
  }

  // Returns true if field adaptedByte is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedByte() {
    return this.adaptedByte != null;
  }

  public Short getAdaptedShort() {
    return this.adaptedShort;
  }

  // Returns true if field adaptedShort is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedShort() {
    return this.adaptedShort != null;
  }

  public Integer getAdaptedInteger() {
    return this.adaptedInteger;
  }

  // Returns true if field adaptedInteger is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedInteger() {
    return this.adaptedInteger != null;
  }

  public Long getAdaptedLong() {
    return this.adaptedLong;
  }

  // Returns true if field adaptedLong is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedLong() {
    return this.adaptedLong != null;
  }

  public Double getAdaptedDouble() {
    return this.adaptedDouble;
  }

  // Returns true if field adaptedDouble is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedDouble() {
    return this.adaptedDouble != null;
  }

  public String getAdaptedString() {
    return this.adaptedString;
  }

  // Returns true if field adaptedString is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedString() {
    return this.adaptedString != null;
  }

  public List<Long> getAdaptedList() {
    return this.adaptedList;
  }

  // Returns true if field adaptedList is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedList() {
    return this.adaptedList != null;
  }

  public Set<Long> getAdaptedSet() {
    return this.adaptedSet;
  }

  // Returns true if field adaptedSet is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedSet() {
    return this.adaptedSet != null;
  }

  public Map<Long,Long> getAdaptedMap() {
    return this.adaptedMap;
  }

  // Returns true if field adaptedMap is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedMap() {
    return this.adaptedMap != null;
  }

  public Boolean isAdaptedBoolDefault() {
    return this.adaptedBoolDefault;
  }

  // Returns true if field adaptedBoolDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedBoolDefault() {
    return this.adaptedBoolDefault != null;
  }

  public Byte getAdaptedByteDefault() {
    return this.adaptedByteDefault;
  }

  // Returns true if field adaptedByteDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedByteDefault() {
    return this.adaptedByteDefault != null;
  }

  public Short getAdaptedShortDefault() {
    return this.adaptedShortDefault;
  }

  // Returns true if field adaptedShortDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedShortDefault() {
    return this.adaptedShortDefault != null;
  }

  public Integer getAdaptedIntegerDefault() {
    return this.adaptedIntegerDefault;
  }

  // Returns true if field adaptedIntegerDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedIntegerDefault() {
    return this.adaptedIntegerDefault != null;
  }

  public Long getAdaptedLongDefault() {
    return this.adaptedLongDefault;
  }

  // Returns true if field adaptedLongDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedLongDefault() {
    return this.adaptedLongDefault != null;
  }

  public Double getAdaptedDoubleDefault() {
    return this.adaptedDoubleDefault;
  }

  // Returns true if field adaptedDoubleDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedDoubleDefault() {
    return this.adaptedDoubleDefault != null;
  }

  public String getAdaptedStringDefault() {
    return this.adaptedStringDefault;
  }

  // Returns true if field adaptedStringDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedStringDefault() {
    return this.adaptedStringDefault != null;
  }

  public ThriftAdaptedEnum getAdaptedEnum() {
    return this.adaptedEnum;
  }

  // Returns true if field adaptedEnum is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedEnum() {
    return this.adaptedEnum != null;
  }

  public List<Long> getAdaptedListDefault() {
    return this.adaptedListDefault;
  }

  // Returns true if field adaptedListDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedListDefault() {
    return this.adaptedListDefault != null;
  }

  public Set<Long> getAdaptedSetDefault() {
    return this.adaptedSetDefault;
  }

  // Returns true if field adaptedSetDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedSetDefault() {
    return this.adaptedSetDefault != null;
  }

  public Map<Long,Long> getAdaptedMapDefault() {
    return this.adaptedMapDefault;
  }

  // Returns true if field adaptedMapDefault is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedMapDefault() {
    return this.adaptedMapDefault != null;
  }

  public Boolean isDoubleTypedefBool() {
    return this.doubleTypedefBool;
  }

  // Returns true if field doubleTypedefBool is set (has been assigned a value) and false otherwise
  public boolean isSetDoubleTypedefBool() {
    return this.doubleTypedefBool != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof AdaptTemplatedTestStruct))
      return false;
    AdaptTemplatedTestStruct that = (AdaptTemplatedTestStruct)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedBool(), that.isSetAdaptedBool(), this.adaptedBool, that.adaptedBool)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedByte(), that.isSetAdaptedByte(), this.adaptedByte, that.adaptedByte)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedShort(), that.isSetAdaptedShort(), this.adaptedShort, that.adaptedShort)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedInteger(), that.isSetAdaptedInteger(), this.adaptedInteger, that.adaptedInteger)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedLong(), that.isSetAdaptedLong(), this.adaptedLong, that.adaptedLong)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedDouble(), that.isSetAdaptedDouble(), this.adaptedDouble, that.adaptedDouble)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedString(), that.isSetAdaptedString(), this.adaptedString, that.adaptedString)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedList(), that.isSetAdaptedList(), this.adaptedList, that.adaptedList)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedSet(), that.isSetAdaptedSet(), this.adaptedSet, that.adaptedSet)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedMap(), that.isSetAdaptedMap(), this.adaptedMap, that.adaptedMap)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedBoolDefault(), that.isSetAdaptedBoolDefault(), this.adaptedBoolDefault, that.adaptedBoolDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedByteDefault(), that.isSetAdaptedByteDefault(), this.adaptedByteDefault, that.adaptedByteDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedShortDefault(), that.isSetAdaptedShortDefault(), this.adaptedShortDefault, that.adaptedShortDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedIntegerDefault(), that.isSetAdaptedIntegerDefault(), this.adaptedIntegerDefault, that.adaptedIntegerDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedLongDefault(), that.isSetAdaptedLongDefault(), this.adaptedLongDefault, that.adaptedLongDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedDoubleDefault(), that.isSetAdaptedDoubleDefault(), this.adaptedDoubleDefault, that.adaptedDoubleDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedStringDefault(), that.isSetAdaptedStringDefault(), this.adaptedStringDefault, that.adaptedStringDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedEnum(), that.isSetAdaptedEnum(), this.adaptedEnum, that.adaptedEnum)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedListDefault(), that.isSetAdaptedListDefault(), this.adaptedListDefault, that.adaptedListDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedSetDefault(), that.isSetAdaptedSetDefault(), this.adaptedSetDefault, that.adaptedSetDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedMapDefault(), that.isSetAdaptedMapDefault(), this.adaptedMapDefault, that.adaptedMapDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetDoubleTypedefBool(), that.isSetDoubleTypedefBool(), this.doubleTypedefBool, that.doubleTypedefBool)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {adaptedBool, adaptedByte, adaptedShort, adaptedInteger, adaptedLong, adaptedDouble, adaptedString, adaptedList, adaptedSet, adaptedMap, adaptedBoolDefault, adaptedByteDefault, adaptedShortDefault, adaptedIntegerDefault, adaptedLongDefault, adaptedDoubleDefault, adaptedStringDefault, adaptedEnum, adaptedListDefault, adaptedSetDefault, adaptedMapDefault, doubleTypedefBool});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static AdaptTemplatedTestStruct deserialize(TProtocol iprot) throws TException {
    Boolean tmp_adaptedBool = null;
    Byte tmp_adaptedByte = null;
    Short tmp_adaptedShort = null;
    Integer tmp_adaptedInteger = null;
    Long tmp_adaptedLong = null;
    Double tmp_adaptedDouble = null;
    String tmp_adaptedString = null;
    List<Long> tmp_adaptedList = null;
    Set<Long> tmp_adaptedSet = null;
    Map<Long,Long> tmp_adaptedMap = null;
    Boolean tmp_adaptedBoolDefault = null;
    Byte tmp_adaptedByteDefault = null;
    Short tmp_adaptedShortDefault = null;
    Integer tmp_adaptedIntegerDefault = null;
    Long tmp_adaptedLongDefault = null;
    Double tmp_adaptedDoubleDefault = null;
    String tmp_adaptedStringDefault = null;
    ThriftAdaptedEnum tmp_adaptedEnum = null;
    List<Long> tmp_adaptedListDefault = null;
    Set<Long> tmp_adaptedSetDefault = null;
    Map<Long,Long> tmp_adaptedMapDefault = null;
    Boolean tmp_doubleTypedefBool = null;
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
        case ADAPTEDBOOL:
          if (__field.type == TType.BOOL) {
            tmp_adaptedBool = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDBYTE:
          if (__field.type == TType.BYTE) {
            tmp_adaptedByte = iprot.readByte();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSHORT:
          if (__field.type == TType.I16) {
            tmp_adaptedShort = iprot.readI16();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDINTEGER:
          if (__field.type == TType.I32) {
            tmp_adaptedInteger = iprot.readI32();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDLONG:
          if (__field.type == TType.I64) {
            tmp_adaptedLong = iprot.readI64();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDDOUBLE:
          if (__field.type == TType.DOUBLE) {
            tmp_adaptedDouble = iprot.readDouble();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSTRING:
          if (__field.type == TType.STRING) {
            tmp_adaptedString = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDLIST:
          if (__field.type == TType.LIST) {
            {
              TList _list58 = iprot.readListBegin();
              tmp_adaptedList = new ArrayList<Long>(Math.max(0, _list58.size));
              for (int _i59 = 0; 
                   (_list58.size < 0) ? iprot.peekList() : (_i59 < _list58.size); 
                   ++_i59)
              {
                Long _elem60;
                _elem60 = iprot.readI64();
                tmp_adaptedList.add(_elem60);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSET:
          if (__field.type == TType.SET) {
            {
              TSet _set61 = iprot.readSetBegin();
              tmp_adaptedSet = new HashSet<Long>(Math.max(0, 2*_set61.size));
              for (int _i62 = 0; 
                   (_set61.size < 0) ? iprot.peekSet() : (_i62 < _set61.size); 
                   ++_i62)
              {
                Long _elem63;
                _elem63 = iprot.readI64();
                tmp_adaptedSet.add(_elem63);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDMAP:
          if (__field.type == TType.MAP) {
            {
              TMap _map64 = iprot.readMapBegin();
              tmp_adaptedMap = new HashMap<Long,Long>(Math.max(0, 2*_map64.size));
              for (int _i65 = 0; 
                   (_map64.size < 0) ? iprot.peekMap() : (_i65 < _map64.size); 
                   ++_i65)
              {
                Long _key66;
                Long _val67;
                _key66 = iprot.readI64();
                _val67 = iprot.readI64();
                tmp_adaptedMap.put(_key66, _val67);
              }
              iprot.readMapEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDBOOLDEFAULT:
          if (__field.type == TType.BOOL) {
            tmp_adaptedBoolDefault = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDBYTEDEFAULT:
          if (__field.type == TType.BYTE) {
            tmp_adaptedByteDefault = iprot.readByte();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSHORTDEFAULT:
          if (__field.type == TType.I16) {
            tmp_adaptedShortDefault = iprot.readI16();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDINTEGERDEFAULT:
          if (__field.type == TType.I32) {
            tmp_adaptedIntegerDefault = iprot.readI32();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDLONGDEFAULT:
          if (__field.type == TType.I64) {
            tmp_adaptedLongDefault = iprot.readI64();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDDOUBLEDEFAULT:
          if (__field.type == TType.DOUBLE) {
            tmp_adaptedDoubleDefault = iprot.readDouble();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSTRINGDEFAULT:
          if (__field.type == TType.STRING) {
            tmp_adaptedStringDefault = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDENUM:
          if (__field.type == TType.I32) {
            tmp_adaptedEnum = ThriftAdaptedEnum.findByValue(iprot.readI32());
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDLISTDEFAULT:
          if (__field.type == TType.LIST) {
            {
              TList _list68 = iprot.readListBegin();
              tmp_adaptedListDefault = new ArrayList<Long>(Math.max(0, _list68.size));
              for (int _i69 = 0; 
                   (_list68.size < 0) ? iprot.peekList() : (_i69 < _list68.size); 
                   ++_i69)
              {
                Long _elem70;
                _elem70 = iprot.readI64();
                tmp_adaptedListDefault.add(_elem70);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSETDEFAULT:
          if (__field.type == TType.SET) {
            {
              TSet _set71 = iprot.readSetBegin();
              tmp_adaptedSetDefault = new HashSet<Long>(Math.max(0, 2*_set71.size));
              for (int _i72 = 0; 
                   (_set71.size < 0) ? iprot.peekSet() : (_i72 < _set71.size); 
                   ++_i72)
              {
                Long _elem73;
                _elem73 = iprot.readI64();
                tmp_adaptedSetDefault.add(_elem73);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDMAPDEFAULT:
          if (__field.type == TType.MAP) {
            {
              TMap _map74 = iprot.readMapBegin();
              tmp_adaptedMapDefault = new HashMap<Long,Long>(Math.max(0, 2*_map74.size));
              for (int _i75 = 0; 
                   (_map74.size < 0) ? iprot.peekMap() : (_i75 < _map74.size); 
                   ++_i75)
              {
                Long _key76;
                Long _val77;
                _key76 = iprot.readI64();
                _val77 = iprot.readI64();
                tmp_adaptedMapDefault.put(_key76, _val77);
              }
              iprot.readMapEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case DOUBLETYPEDEFBOOL:
          if (__field.type == TType.BOOL) {
            tmp_doubleTypedefBool = iprot.readBool();
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

    AdaptTemplatedTestStruct _that;
    _that = new AdaptTemplatedTestStruct(
      tmp_adaptedBool
      ,tmp_adaptedByte
      ,tmp_adaptedShort
      ,tmp_adaptedInteger
      ,tmp_adaptedLong
      ,tmp_adaptedDouble
      ,tmp_adaptedString
      ,tmp_adaptedList
      ,tmp_adaptedSet
      ,tmp_adaptedMap
      ,tmp_adaptedBoolDefault
      ,tmp_adaptedByteDefault
      ,tmp_adaptedShortDefault
      ,tmp_adaptedIntegerDefault
      ,tmp_adaptedLongDefault
      ,tmp_adaptedDoubleDefault
      ,tmp_adaptedStringDefault
      ,tmp_adaptedEnum
      ,tmp_adaptedListDefault
      ,tmp_adaptedSetDefault
      ,tmp_adaptedMapDefault
      ,tmp_doubleTypedefBool
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.adaptedBool != null) {
      oprot.writeFieldBegin(ADAPTED_BOOL_FIELD_DESC);
      oprot.writeBool(this.adaptedBool);
      oprot.writeFieldEnd();
    }
    if (this.adaptedByte != null) {
      oprot.writeFieldBegin(ADAPTED_BYTE_FIELD_DESC);
      oprot.writeByte(this.adaptedByte);
      oprot.writeFieldEnd();
    }
    if (this.adaptedShort != null) {
      oprot.writeFieldBegin(ADAPTED_SHORT_FIELD_DESC);
      oprot.writeI16(this.adaptedShort);
      oprot.writeFieldEnd();
    }
    if (this.adaptedInteger != null) {
      oprot.writeFieldBegin(ADAPTED_INTEGER_FIELD_DESC);
      oprot.writeI32(this.adaptedInteger);
      oprot.writeFieldEnd();
    }
    if (this.adaptedLong != null) {
      oprot.writeFieldBegin(ADAPTED_LONG_FIELD_DESC);
      oprot.writeI64(this.adaptedLong);
      oprot.writeFieldEnd();
    }
    if (this.adaptedDouble != null) {
      oprot.writeFieldBegin(ADAPTED_DOUBLE_FIELD_DESC);
      oprot.writeDouble(this.adaptedDouble);
      oprot.writeFieldEnd();
    }
    if (this.adaptedString != null) {
      oprot.writeFieldBegin(ADAPTED_STRING_FIELD_DESC);
      oprot.writeString(this.adaptedString);
      oprot.writeFieldEnd();
    }
    if (this.adaptedList != null) {
      oprot.writeFieldBegin(ADAPTED_LIST_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.I64, this.adaptedList.size()));
        for (Long _iter78 : this.adaptedList)        {
          oprot.writeI64(_iter78);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.adaptedSet != null) {
      oprot.writeFieldBegin(ADAPTED_SET_FIELD_DESC);
      {
        oprot.writeSetBegin(new TSet(TType.I64, this.adaptedSet.size()));
        for (Long _iter79 : this.adaptedSet)        {
          oprot.writeI64(_iter79);
        }
        oprot.writeSetEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.adaptedMap != null) {
      oprot.writeFieldBegin(ADAPTED_MAP_FIELD_DESC);
      {
        oprot.writeMapBegin(new TMap(TType.I64, TType.I64, this.adaptedMap.size()));
        for (Map.Entry<Long, Long> _iter80 : this.adaptedMap.entrySet())        {
          oprot.writeI64(_iter80.getKey());
          oprot.writeI64(_iter80.getValue());
        }
        oprot.writeMapEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.adaptedBoolDefault != null) {
      oprot.writeFieldBegin(ADAPTED_BOOL_DEFAULT_FIELD_DESC);
      oprot.writeBool(this.adaptedBoolDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedByteDefault != null) {
      oprot.writeFieldBegin(ADAPTED_BYTE_DEFAULT_FIELD_DESC);
      oprot.writeByte(this.adaptedByteDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedShortDefault != null) {
      oprot.writeFieldBegin(ADAPTED_SHORT_DEFAULT_FIELD_DESC);
      oprot.writeI16(this.adaptedShortDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedIntegerDefault != null) {
      oprot.writeFieldBegin(ADAPTED_INTEGER_DEFAULT_FIELD_DESC);
      oprot.writeI32(this.adaptedIntegerDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedLongDefault != null) {
      oprot.writeFieldBegin(ADAPTED_LONG_DEFAULT_FIELD_DESC);
      oprot.writeI64(this.adaptedLongDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedDoubleDefault != null) {
      oprot.writeFieldBegin(ADAPTED_DOUBLE_DEFAULT_FIELD_DESC);
      oprot.writeDouble(this.adaptedDoubleDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedStringDefault != null) {
      oprot.writeFieldBegin(ADAPTED_STRING_DEFAULT_FIELD_DESC);
      oprot.writeString(this.adaptedStringDefault);
      oprot.writeFieldEnd();
    }
    if (this.adaptedEnum != null) {
      oprot.writeFieldBegin(ADAPTED_ENUM_FIELD_DESC);
      oprot.writeI32(this.adaptedEnum == null ? 0 : this.adaptedEnum.getValue());
      oprot.writeFieldEnd();
    }
    if (this.adaptedListDefault != null) {
      oprot.writeFieldBegin(ADAPTED_LIST_DEFAULT_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.I64, this.adaptedListDefault.size()));
        for (Long _iter81 : this.adaptedListDefault)        {
          oprot.writeI64(_iter81);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.adaptedSetDefault != null) {
      oprot.writeFieldBegin(ADAPTED_SET_DEFAULT_FIELD_DESC);
      {
        oprot.writeSetBegin(new TSet(TType.I64, this.adaptedSetDefault.size()));
        for (Long _iter82 : this.adaptedSetDefault)        {
          oprot.writeI64(_iter82);
        }
        oprot.writeSetEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.adaptedMapDefault != null) {
      oprot.writeFieldBegin(ADAPTED_MAP_DEFAULT_FIELD_DESC);
      {
        oprot.writeMapBegin(new TMap(TType.I64, TType.I64, this.adaptedMapDefault.size()));
        for (Map.Entry<Long, Long> _iter83 : this.adaptedMapDefault.entrySet())        {
          oprot.writeI64(_iter83.getKey());
          oprot.writeI64(_iter83.getValue());
        }
        oprot.writeMapEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.doubleTypedefBool != null) {
      oprot.writeFieldBegin(DOUBLE_TYPEDEF_BOOL_FIELD_DESC);
      oprot.writeBool(this.doubleTypedefBool);
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
