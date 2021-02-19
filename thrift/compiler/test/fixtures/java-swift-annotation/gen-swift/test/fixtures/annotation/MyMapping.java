/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.annotation;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="MyMapping", builder=MyMapping.Builder.class)
public final class MyMapping {

    @ThriftConstructor
    public MyMapping(
        @com.facebook.swift.codec.ThriftField(value=1, name="lsMap", requiredness=Requiredness.NONE) final com.foo.FastLongStringMap lsMap,
        @com.facebook.swift.codec.ThriftField(value=2, name="ioMap", requiredness=Requiredness.NONE) final com.foo.FastIntObjectMap<com.foo.FastIntLongMap> ioMap
    ) {
        this.lsMap = lsMap;
        this.ioMap = ioMap;
    }
    
    @ThriftConstructor
    protected MyMapping() {
      this.lsMap = null;
      this.ioMap = null;
    }
    
    public static class Builder {
    
        private com.foo.FastLongStringMap lsMap = null;
        private com.foo.FastIntObjectMap<com.foo.FastIntLongMap> ioMap = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="lsMap", requiredness=Requiredness.NONE)
        public Builder setLsMap(com.foo.FastLongStringMap lsMap) {
            this.lsMap = lsMap;
            return this;
        }
    
        public com.foo.FastLongStringMap getLsMap() { return lsMap; }
    
            @com.facebook.swift.codec.ThriftField(value=2, name="ioMap", requiredness=Requiredness.NONE)
        public Builder setIoMap(com.foo.FastIntObjectMap<com.foo.FastIntLongMap> ioMap) {
            this.ioMap = ioMap;
            return this;
        }
    
        public com.foo.FastIntObjectMap<com.foo.FastIntLongMap> getIoMap() { return ioMap; }
    
        public Builder() { }
        public Builder(MyMapping other) {
            this.lsMap = other.lsMap;
            this.ioMap = other.ioMap;
        }
    
        @ThriftConstructor
        public MyMapping build() {
            MyMapping result = new MyMapping (
                this.lsMap,
                this.ioMap
            );
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyMapping");
    private final com.foo.FastLongStringMap lsMap;
    public static final int _LSMAP = 1;
    private static final TField LS_MAP_FIELD_DESC = new TField("lsMap", TType.MAP, (short)1);
        private final com.foo.FastIntObjectMap<com.foo.FastIntLongMap> ioMap;
    public static final int _IOMAP = 2;
    private static final TField IO_MAP_FIELD_DESC = new TField("ioMap", TType.MAP, (short)2);
    static {
      NAMES_TO_IDS.put("lsMap", 1);
      FIELD_METADATA.put(1, LS_MAP_FIELD_DESC);
      NAMES_TO_IDS.put("ioMap", 2);
      FIELD_METADATA.put(2, IO_MAP_FIELD_DESC);
    }
    
    @com.facebook.swift.codec.ThriftField(value=1, name="lsMap", requiredness=Requiredness.NONE)
    public com.foo.FastLongStringMap getLsMap() { return lsMap; }
    
    
    @com.facebook.swift.codec.ThriftField(value=2, name="ioMap", requiredness=Requiredness.NONE)
    public com.foo.FastIntObjectMap<com.foo.FastIntLongMap> getIoMap() { return ioMap; }
    
    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("lsMap", lsMap);
        helper.add("ioMap", ioMap);
        return helper.toString();
    }
    
    @java.lang.Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyMapping other = (MyMapping)o;
    
        return
            Objects.equals(lsMap, other.lsMap) &&
            Objects.equals(ioMap, other.ioMap) &&
            true;
    }
    
    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            lsMap,
            ioMap
        });
    }
    
    
    public static MyMapping read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyMapping.NAMES_TO_IDS, MyMapping.FIELD_METADATA);
      MyMapping.Builder builder = new MyMapping.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _LSMAP:
          if (__field.type == TType.MAP) {
            com.foo.FastLongStringMap lsMap;
            {
            TMap _map = oprot.readMapBegin();
            lsMap = new com.foo.FastLongStringMap();
            for (int _i = 0; (_map.size < 0) ? oprot.peekMap() : (_i < _map.size); _i++) {
                
                long _key1 = oprot.readI64();
                String _value1 = oprot.readString();
                lsMap.put(_key1, _value1);
            }
            }
            oprot.readMapEnd();
            builder.setLsMap(lsMap);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _IOMAP:
          if (__field.type == TType.MAP) {
            com.foo.FastIntObjectMap<com.foo.FastIntLongMap> ioMap;
            {
            TMap _map = oprot.readMapBegin();
            ioMap = new com.foo.FastIntObjectMap<com.foo.FastIntLongMap>();
            for (int _i = 0; (_map.size < 0) ? oprot.peekMap() : (_i < _map.size); _i++) {
                
                int _key1 = oprot.readI32();
                com.foo.FastIntLongMap _value1;
            {
            TMap _map1 = oprot.readMapBegin();
            _value1 = new com.foo.FastIntLongMap();
            for (int _i1 = 0; (_map1.size < 0) ? oprot.peekMap() : (_i1 < _map1.size); _i1++) {
                
                
                int _key2 = oprot.readI32();
                

                
                long _value2 = oprot.readI64();
                
                
                _value1.put(_key2, _value2);
                
            }
            }
            oprot.readMapEnd();
                ioMap.put(_key1, _value1);
            }
            }
            oprot.readMapEnd();
            builder.setIoMap(ioMap);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.lsMap != null) {
        oprot.writeFieldBegin(LS_MAP_FIELD_DESC);
        com.foo.FastLongStringMap _iter0 = this.lsMap;
        oprot.writeMapBegin(new TMap(TType.I64, TType.STRING, _iter0.size()));
        for (Map.Entry<Long, String> _iter1 : _iter0.entrySet()) {
          oprot.writeI64(_iter1.getKey());
          oprot.writeString(_iter1.getValue());
        }
        oprot.writeMapEnd();
        oprot.writeFieldEnd();
      }
      if (this.ioMap != null) {
        oprot.writeFieldBegin(IO_MAP_FIELD_DESC);
        com.foo.FastIntObjectMap<com.foo.FastIntLongMap> _iter0 = this.ioMap;
        oprot.writeMapBegin(new TMap(TType.I32, TType.MAP, _iter0.size()));
        for (Map.Entry<Integer, com.foo.FastIntLongMap> _iter1 : _iter0.entrySet()) {
          oprot.writeI32(_iter1.getKey());
          
          oprot.writeMapBegin(new TMap(TType.I32, TType.I64, _iter1.getValue().size()));
        for (Map.Entry<Integer, Long> _iter2 : _iter1.getValue().entrySet()) {
          oprot.writeI32(_iter2.getKey());
          oprot.writeI64(_iter2.getValue());
        }
        oprot.writeMapEnd();
        }
        oprot.writeMapEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static final MyMapping _DEFAULT = new MyMapping.Builder().build();
    
    public static MyMapping defaultInstance() {
        return _DEFAULT;
    }
}
