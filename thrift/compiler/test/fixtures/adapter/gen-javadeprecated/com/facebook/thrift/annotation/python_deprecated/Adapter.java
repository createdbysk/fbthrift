/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.annotation.python_deprecated;

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

/**
 * An annotation that applies a Python adapter to typedef or field, or directly on struct.
 * This completely replaces the underlying type of a thrift for a custom implementation and
 * uses the specified adapter to convert to and from the underlying Thrift type during (de)serialization.
 * 
 * Example 1:
 * 
 *   @python.Adapter{name = "my.module.DatetimeAdapter", typeHint = "datetime.datetime"}
 *   typedef i64 Datetime
 * 
 * Here the type 'Datetime' has the Python adapter `DatetimeAdapter`.
 * 
 * 
 * Example 2:
 * 
 *   struct User {
 *     @python.Adapter{name = "my.module.DatetimeAdapter", typeHint = "datetime.datetime"}
 *     1: i64 created_at;
 *   }
 * Here the field `created_at` has the Python adapter `DatetimeAdapter`.
 * 
 * 
 * Example 3:
 * 
 * 
 *   @python.Adapter{name = "my.module.AnotherAdapter", typeHint = "my.module.AdaptedFoo"}
 *   struct Foo {
 *     1: string bar;
 *   }
 * 
 * Here the struct `Foo` has the Python adapter `AnotherAdapter`.
 * 
 */
@SuppressWarnings({ "unused", "serial" })
public class Adapter implements TBase, java.io.Serializable, Cloneable, Comparable<Adapter> {
  private static final TStruct STRUCT_DESC = new TStruct("Adapter");
  private static final TField NAME_FIELD_DESC = new TField("name", TType.STRING, (short)1);
  private static final TField TYPE_HINT_FIELD_DESC = new TField("typeHint", TType.STRING, (short)2);

  /**
   * Fully qualified name of a Python adapter class, which should inherit from thrift.python.adapter.Adapter
   */
  public String name;
  /**
   * Fully qualified type hint the above implementation adapts to.
   * If ending with "[]", it becomes a generic, and the unadapted type will be filled between the brackets.
   */
  public String typeHint;
  public static final int NAME = 1;
  public static final int TYPEHINT = 2;

  // isset id assignments

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(NAME, new FieldMetaData("name", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(TYPEHINT, new FieldMetaData("typeHint", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(Adapter.class, metaDataMap);
  }

  public Adapter() {
  }

  public Adapter(
      String name,
      String typeHint) {
    this();
    this.name = name;
    this.typeHint = typeHint;
  }

  public static class Builder {
    private String name;
    private String typeHint;

    public Builder() {
    }

    public Builder setName(final String name) {
      this.name = name;
      return this;
    }

    public Builder setTypeHint(final String typeHint) {
      this.typeHint = typeHint;
      return this;
    }

    public Adapter build() {
      Adapter result = new Adapter();
      result.setName(this.name);
      result.setTypeHint(this.typeHint);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Adapter(Adapter other) {
    if (other.isSetName()) {
      this.name = TBaseHelper.deepCopy(other.name);
    }
    if (other.isSetTypeHint()) {
      this.typeHint = TBaseHelper.deepCopy(other.typeHint);
    }
  }

  public Adapter deepCopy() {
    return new Adapter(this);
  }

  /**
   * Fully qualified name of a Python adapter class, which should inherit from thrift.python.adapter.Adapter
   */
  public String getName() {
    return this.name;
  }

  /**
   * Fully qualified name of a Python adapter class, which should inherit from thrift.python.adapter.Adapter
   */
  public Adapter setName(String name) {
    this.name = name;
    return this;
  }

  public void unsetName() {
    this.name = null;
  }

  // Returns true if field name is set (has been assigned a value) and false otherwise
  public boolean isSetName() {
    return this.name != null;
  }

  public void setNameIsSet(boolean __value) {
    if (!__value) {
      this.name = null;
    }
  }

  /**
   * Fully qualified type hint the above implementation adapts to.
   * If ending with "[]", it becomes a generic, and the unadapted type will be filled between the brackets.
   */
  public String getTypeHint() {
    return this.typeHint;
  }

  /**
   * Fully qualified type hint the above implementation adapts to.
   * If ending with "[]", it becomes a generic, and the unadapted type will be filled between the brackets.
   */
  public Adapter setTypeHint(String typeHint) {
    this.typeHint = typeHint;
    return this;
  }

  public void unsetTypeHint() {
    this.typeHint = null;
  }

  // Returns true if field typeHint is set (has been assigned a value) and false otherwise
  public boolean isSetTypeHint() {
    return this.typeHint != null;
  }

  public void setTypeHintIsSet(boolean __value) {
    if (!__value) {
      this.typeHint = null;
    }
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case NAME:
      if (__value == null) {
        unsetName();
      } else {
        setName((String)__value);
      }
      break;

    case TYPEHINT:
      if (__value == null) {
        unsetTypeHint();
      } else {
        setTypeHint((String)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case NAME:
      return getName();

    case TYPEHINT:
      return getTypeHint();

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof Adapter))
      return false;
    Adapter that = (Adapter)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetName(), that.isSetName(), this.name, that.name)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetTypeHint(), that.isSetTypeHint(), this.typeHint, that.typeHint)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {name, typeHint});
  }

  @Override
  public int compareTo(Adapter other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetName()).compareTo(other.isSetName());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(name, other.name);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetTypeHint()).compareTo(other.isSetTypeHint());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(typeHint, other.typeHint);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin(metaDataMap);
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case NAME:
          if (__field.type == TType.STRING) {
            this.name = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case TYPEHINT:
          if (__field.type == TType.STRING) {
            this.typeHint = iprot.readString();
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


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.name != null) {
      oprot.writeFieldBegin(NAME_FIELD_DESC);
      oprot.writeString(this.name);
      oprot.writeFieldEnd();
    }
    if (this.typeHint != null) {
      oprot.writeFieldBegin(TYPE_HINT_FIELD_DESC);
      oprot.writeString(this.typeHint);
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
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("Adapter");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("name");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getName() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getName(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("typeHint");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getTypeHint() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getTypeHint(), indent + 1, prettyPrint));
    }
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

