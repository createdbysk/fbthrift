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
public class Foo implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("Foo");
  private static final TField INT_FIELD_FIELD_DESC = new TField("intField", TType.I32, (short)1);
  private static final TField OPTIONAL_INT_FIELD_FIELD_DESC = new TField("optionalIntField", TType.I32, (short)2);
  private static final TField INT_FIELD_WITH_DEFAULT_FIELD_DESC = new TField("intFieldWithDefault", TType.I32, (short)3);
  private static final TField SET_FIELD_FIELD_DESC = new TField("setField", TType.SET, (short)4);
  private static final TField OPTIONAL_SET_FIELD_FIELD_DESC = new TField("optionalSetField", TType.SET, (short)5);
  private static final TField MAP_FIELD_FIELD_DESC = new TField("mapField", TType.MAP, (short)6);
  private static final TField OPTIONAL_MAP_FIELD_FIELD_DESC = new TField("optionalMapField", TType.MAP, (short)7);
  private static final TField BINARY_FIELD_FIELD_DESC = new TField("binaryField", TType.STRING, (short)8);
  private static final TField LONG_FIELD_FIELD_DESC = new TField("longField", TType.I64, (short)9);
  private static final TField ADAPTED_LONG_FIELD_FIELD_DESC = new TField("adaptedLongField", TType.I64, (short)10);
  private static final TField DOUBLE_ADAPTED_FIELD_FIELD_DESC = new TField("doubleAdaptedField", TType.I64, (short)11);

  public final Integer intField;
  public final Integer optionalIntField;
  public final Integer intFieldWithDefault;
  public final Set<String> setField;
  public final Set<String> optionalSetField;
  public final Map<String,List<String>> mapField;
  public final Map<String,List<String>> optionalMapField;
  public final byte[] binaryField;
  public final Long longField;
  public final Long adaptedLongField;
  public final Long doubleAdaptedField;
  public static final int INTFIELD = 1;
  public static final int OPTIONALINTFIELD = 2;
  public static final int INTFIELDWITHDEFAULT = 3;
  public static final int SETFIELD = 4;
  public static final int OPTIONALSETFIELD = 5;
  public static final int MAPFIELD = 6;
  public static final int OPTIONALMAPFIELD = 7;
  public static final int BINARYFIELD = 8;
  public static final int LONGFIELD = 9;
  public static final int ADAPTEDLONGFIELD = 10;
  public static final int DOUBLEADAPTEDFIELD = 11;

  public Foo(
      Integer intField,
      Integer optionalIntField,
      Integer intFieldWithDefault,
      Set<String> setField,
      Set<String> optionalSetField,
      Map<String,List<String>> mapField,
      Map<String,List<String>> optionalMapField,
      byte[] binaryField,
      Long longField,
      Long adaptedLongField,
      Long doubleAdaptedField) {
    this.intField = intField;
    this.optionalIntField = optionalIntField;
    this.intFieldWithDefault = intFieldWithDefault;
    this.setField = setField;
    this.optionalSetField = optionalSetField;
    this.mapField = mapField;
    this.optionalMapField = optionalMapField;
    this.binaryField = binaryField;
    this.longField = longField;
    this.adaptedLongField = adaptedLongField;
    this.doubleAdaptedField = doubleAdaptedField;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Foo(Foo other) {
    if (other.isSetIntField()) {
      this.intField = TBaseHelper.deepCopy(other.intField);
    } else {
      this.intField = null;
    }
    if (other.isSetOptionalIntField()) {
      this.optionalIntField = TBaseHelper.deepCopy(other.optionalIntField);
    } else {
      this.optionalIntField = null;
    }
    if (other.isSetIntFieldWithDefault()) {
      this.intFieldWithDefault = TBaseHelper.deepCopy(other.intFieldWithDefault);
    } else {
      this.intFieldWithDefault = null;
    }
    if (other.isSetSetField()) {
      this.setField = TBaseHelper.deepCopy(other.setField);
    } else {
      this.setField = null;
    }
    if (other.isSetOptionalSetField()) {
      this.optionalSetField = TBaseHelper.deepCopy(other.optionalSetField);
    } else {
      this.optionalSetField = null;
    }
    if (other.isSetMapField()) {
      this.mapField = TBaseHelper.deepCopy(other.mapField);
    } else {
      this.mapField = null;
    }
    if (other.isSetOptionalMapField()) {
      this.optionalMapField = TBaseHelper.deepCopy(other.optionalMapField);
    } else {
      this.optionalMapField = null;
    }
    if (other.isSetBinaryField()) {
      this.binaryField = TBaseHelper.deepCopy(other.binaryField);
    } else {
      this.binaryField = null;
    }
    if (other.isSetLongField()) {
      this.longField = TBaseHelper.deepCopy(other.longField);
    } else {
      this.longField = null;
    }
    if (other.isSetAdaptedLongField()) {
      this.adaptedLongField = TBaseHelper.deepCopy(other.adaptedLongField);
    } else {
      this.adaptedLongField = null;
    }
    if (other.isSetDoubleAdaptedField()) {
      this.doubleAdaptedField = TBaseHelper.deepCopy(other.doubleAdaptedField);
    } else {
      this.doubleAdaptedField = null;
    }
  }

  public Foo deepCopy() {
    return new Foo(this);
  }

  public Integer getIntField() {
    return this.intField;
  }

  // Returns true if field intField is set (has been assigned a value) and false otherwise
  public boolean isSetIntField() {
    return this.intField != null;
  }

  public Integer getOptionalIntField() {
    return this.optionalIntField;
  }

  // Returns true if field optionalIntField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalIntField() {
    return this.optionalIntField != null;
  }

  public Integer getIntFieldWithDefault() {
    return this.intFieldWithDefault;
  }

  // Returns true if field intFieldWithDefault is set (has been assigned a value) and false otherwise
  public boolean isSetIntFieldWithDefault() {
    return this.intFieldWithDefault != null;
  }

  public Set<String> getSetField() {
    return this.setField;
  }

  // Returns true if field setField is set (has been assigned a value) and false otherwise
  public boolean isSetSetField() {
    return this.setField != null;
  }

  public Set<String> getOptionalSetField() {
    return this.optionalSetField;
  }

  // Returns true if field optionalSetField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalSetField() {
    return this.optionalSetField != null;
  }

  public Map<String,List<String>> getMapField() {
    return this.mapField;
  }

  // Returns true if field mapField is set (has been assigned a value) and false otherwise
  public boolean isSetMapField() {
    return this.mapField != null;
  }

  public Map<String,List<String>> getOptionalMapField() {
    return this.optionalMapField;
  }

  // Returns true if field optionalMapField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalMapField() {
    return this.optionalMapField != null;
  }

  public byte[] getBinaryField() {
    return this.binaryField;
  }

  // Returns true if field binaryField is set (has been assigned a value) and false otherwise
  public boolean isSetBinaryField() {
    return this.binaryField != null;
  }

  public Long getLongField() {
    return this.longField;
  }

  // Returns true if field longField is set (has been assigned a value) and false otherwise
  public boolean isSetLongField() {
    return this.longField != null;
  }

  public Long getAdaptedLongField() {
    return this.adaptedLongField;
  }

  // Returns true if field adaptedLongField is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedLongField() {
    return this.adaptedLongField != null;
  }

  public Long getDoubleAdaptedField() {
    return this.doubleAdaptedField;
  }

  // Returns true if field doubleAdaptedField is set (has been assigned a value) and false otherwise
  public boolean isSetDoubleAdaptedField() {
    return this.doubleAdaptedField != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof Foo))
      return false;
    Foo that = (Foo)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetIntField(), that.isSetIntField(), this.intField, that.intField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalIntField(), that.isSetOptionalIntField(), this.optionalIntField, that.optionalIntField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetIntFieldWithDefault(), that.isSetIntFieldWithDefault(), this.intFieldWithDefault, that.intFieldWithDefault)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetSetField(), that.isSetSetField(), this.setField, that.setField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalSetField(), that.isSetOptionalSetField(), this.optionalSetField, that.optionalSetField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetMapField(), that.isSetMapField(), this.mapField, that.mapField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalMapField(), that.isSetOptionalMapField(), this.optionalMapField, that.optionalMapField)) { return false; }

    if (!TBaseHelper.equalsSlow(this.isSetBinaryField(), that.isSetBinaryField(), this.binaryField, that.binaryField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetLongField(), that.isSetLongField(), this.longField, that.longField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedLongField(), that.isSetAdaptedLongField(), this.adaptedLongField, that.adaptedLongField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetDoubleAdaptedField(), that.isSetDoubleAdaptedField(), this.doubleAdaptedField, that.doubleAdaptedField)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {intField, optionalIntField, intFieldWithDefault, setField, optionalSetField, mapField, optionalMapField, binaryField, longField, adaptedLongField, doubleAdaptedField});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static Foo deserialize(TProtocol iprot) throws TException {
    Integer tmp_intField = null;
    Integer tmp_optionalIntField = null;
    Integer tmp_intFieldWithDefault = null;
    Set<String> tmp_setField = null;
    Set<String> tmp_optionalSetField = null;
    Map<String,List<String>> tmp_mapField = null;
    Map<String,List<String>> tmp_optionalMapField = null;
    byte[] tmp_binaryField = null;
    Long tmp_longField = null;
    Long tmp_adaptedLongField = null;
    Long tmp_doubleAdaptedField = null;
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
        case INTFIELD:
          if (__field.type == TType.I32) {
            tmp_intField = iprot.readI32();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALINTFIELD:
          if (__field.type == TType.I32) {
            tmp_optionalIntField = iprot.readI32();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INTFIELDWITHDEFAULT:
          if (__field.type == TType.I32) {
            tmp_intFieldWithDefault = iprot.readI32();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case SETFIELD:
          if (__field.type == TType.SET) {
            {
              TSet _set0 = iprot.readSetBegin();
              tmp_setField = new HashSet<String>(Math.max(0, 2*_set0.size));
              for (int _i1 = 0; 
                   (_set0.size < 0) ? iprot.peekSet() : (_i1 < _set0.size); 
                   ++_i1)
              {
                String _elem2;
                _elem2 = iprot.readString();
                tmp_setField.add(_elem2);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALSETFIELD:
          if (__field.type == TType.SET) {
            {
              TSet _set3 = iprot.readSetBegin();
              tmp_optionalSetField = new HashSet<String>(Math.max(0, 2*_set3.size));
              for (int _i4 = 0; 
                   (_set3.size < 0) ? iprot.peekSet() : (_i4 < _set3.size); 
                   ++_i4)
              {
                String _elem5;
                _elem5 = iprot.readString();
                tmp_optionalSetField.add(_elem5);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case MAPFIELD:
          if (__field.type == TType.MAP) {
            {
              TMap _map6 = iprot.readMapBegin();
              tmp_mapField = new HashMap<String,List<String>>(Math.max(0, 2*_map6.size));
              for (int _i7 = 0; 
                   (_map6.size < 0) ? iprot.peekMap() : (_i7 < _map6.size); 
                   ++_i7)
              {
                String _key8;
                List<String> _val9;
                _key8 = iprot.readString();
                {
                  TList _list10 = iprot.readListBegin();
                  _val9 = new ArrayList<String>(Math.max(0, _list10.size));
                  for (int _i11 = 0; 
                       (_list10.size < 0) ? iprot.peekList() : (_i11 < _list10.size); 
                       ++_i11)
                  {
                    String _elem12;
                    _elem12 = iprot.readString();
                    _val9.add(_elem12);
                  }
                  iprot.readListEnd();
                }
                tmp_mapField.put(_key8, _val9);
              }
              iprot.readMapEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALMAPFIELD:
          if (__field.type == TType.MAP) {
            {
              TMap _map13 = iprot.readMapBegin();
              tmp_optionalMapField = new HashMap<String,List<String>>(Math.max(0, 2*_map13.size));
              for (int _i14 = 0; 
                   (_map13.size < 0) ? iprot.peekMap() : (_i14 < _map13.size); 
                   ++_i14)
              {
                String _key15;
                List<String> _val16;
                _key15 = iprot.readString();
                {
                  TList _list17 = iprot.readListBegin();
                  _val16 = new ArrayList<String>(Math.max(0, _list17.size));
                  for (int _i18 = 0; 
                       (_list17.size < 0) ? iprot.peekList() : (_i18 < _list17.size); 
                       ++_i18)
                  {
                    String _elem19;
                    _elem19 = iprot.readString();
                    _val16.add(_elem19);
                  }
                  iprot.readListEnd();
                }
                tmp_optionalMapField.put(_key15, _val16);
              }
              iprot.readMapEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case BINARYFIELD:
          if (__field.type == TType.STRING) {
            tmp_binaryField = iprot.readBinary();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case LONGFIELD:
          if (__field.type == TType.I64) {
            tmp_longField = iprot.readI64();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDLONGFIELD:
          if (__field.type == TType.I64) {
            tmp_adaptedLongField = iprot.readI64();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case DOUBLEADAPTEDFIELD:
          if (__field.type == TType.I64) {
            tmp_doubleAdaptedField = iprot.readI64();
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

    Foo _that;
    _that = new Foo(
      tmp_intField
      ,tmp_optionalIntField
      ,tmp_intFieldWithDefault
      ,tmp_setField
      ,tmp_optionalSetField
      ,tmp_mapField
      ,tmp_optionalMapField
      ,tmp_binaryField
      ,tmp_longField
      ,tmp_adaptedLongField
      ,tmp_doubleAdaptedField
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.intField != null) {
      oprot.writeFieldBegin(INT_FIELD_FIELD_DESC);
      oprot.writeI32(this.intField);
      oprot.writeFieldEnd();
    }
    if (this.optionalIntField != null) {
      if (isSetOptionalIntField()) {
        oprot.writeFieldBegin(OPTIONAL_INT_FIELD_FIELD_DESC);
        oprot.writeI32(this.optionalIntField);
        oprot.writeFieldEnd();
      }
    }
    if (this.intFieldWithDefault != null) {
      oprot.writeFieldBegin(INT_FIELD_WITH_DEFAULT_FIELD_DESC);
      oprot.writeI32(this.intFieldWithDefault);
      oprot.writeFieldEnd();
    }
    if (this.setField != null) {
      oprot.writeFieldBegin(SET_FIELD_FIELD_DESC);
      {
        oprot.writeSetBegin(new TSet(TType.STRING, this.setField.size()));
        for (String _iter20 : this.setField)        {
          oprot.writeString(_iter20);
        }
        oprot.writeSetEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.optionalSetField != null) {
      if (isSetOptionalSetField()) {
        oprot.writeFieldBegin(OPTIONAL_SET_FIELD_FIELD_DESC);
        {
          oprot.writeSetBegin(new TSet(TType.STRING, this.optionalSetField.size()));
          for (String _iter21 : this.optionalSetField)          {
            oprot.writeString(_iter21);
          }
          oprot.writeSetEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    if (this.mapField != null) {
      oprot.writeFieldBegin(MAP_FIELD_FIELD_DESC);
      {
        oprot.writeMapBegin(new TMap(TType.STRING, TType.LIST, this.mapField.size()));
        for (Map.Entry<String, List<String>> _iter22 : this.mapField.entrySet())        {
          oprot.writeString(_iter22.getKey());
          {
            oprot.writeListBegin(new TList(TType.STRING, _iter22.getValue().size()));
            for (String _iter23 : _iter22.getValue())            {
              oprot.writeString(_iter23);
            }
            oprot.writeListEnd();
          }
        }
        oprot.writeMapEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.optionalMapField != null) {
      if (isSetOptionalMapField()) {
        oprot.writeFieldBegin(OPTIONAL_MAP_FIELD_FIELD_DESC);
        {
          oprot.writeMapBegin(new TMap(TType.STRING, TType.LIST, this.optionalMapField.size()));
          for (Map.Entry<String, List<String>> _iter24 : this.optionalMapField.entrySet())          {
            oprot.writeString(_iter24.getKey());
            {
              oprot.writeListBegin(new TList(TType.STRING, _iter24.getValue().size()));
              for (String _iter25 : _iter24.getValue())              {
                oprot.writeString(_iter25);
              }
              oprot.writeListEnd();
            }
          }
          oprot.writeMapEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    if (this.binaryField != null) {
      oprot.writeFieldBegin(BINARY_FIELD_FIELD_DESC);
      oprot.writeBinary(this.binaryField);
      oprot.writeFieldEnd();
    }
    if (this.longField != null) {
      oprot.writeFieldBegin(LONG_FIELD_FIELD_DESC);
      oprot.writeI64(this.longField);
      oprot.writeFieldEnd();
    }
    if (this.adaptedLongField != null) {
      oprot.writeFieldBegin(ADAPTED_LONG_FIELD_FIELD_DESC);
      oprot.writeI64(this.adaptedLongField);
      oprot.writeFieldEnd();
    }
    if (this.doubleAdaptedField != null) {
      oprot.writeFieldBegin(DOUBLE_ADAPTED_FIELD_FIELD_DESC);
      oprot.writeI64(this.doubleAdaptedField);
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

