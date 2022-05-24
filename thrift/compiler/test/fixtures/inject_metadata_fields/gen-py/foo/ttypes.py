#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from __future__ import absolute_import
import sys
from thrift.util.Recursive import fix_spec
from thrift.Thrift import TType, TMessageType, TPriority, TRequestContext, TProcessorEventHandler, TServerInterface, TProcessor, TException, TApplicationException, UnimplementedTypedef
from thrift.protocol.TProtocol import TProtocolException


import thrift.annotation.thrift.ttypes


import pprint
import warnings
from thrift import Thrift
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.protocol import TCompactProtocol
from thrift.protocol import THeaderProtocol
fastproto = None
try:
  from thrift.protocol import fastproto
except ImportError:
  pass
all_structs = []
UTF8STRINGS = bool(0) or sys.version_info.major >= 3

__all__ = ['UTF8STRINGS', 'Fields']

class Fields:
  """
  Attributes:
   - injected_field
   - injected_structured_annotation_field
   - injected_unstructured_annotation_field
  """

  thrift_spec = None
  thrift_field_annotations = None
  thrift_struct_annotations = None
  __init__ = None
  @staticmethod
  def isUnion():
    return False

  def read(self, iprot):
    if (isinstance(iprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0)
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2)
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 100:
        if ftype == TType.STRING:
          self.injected_field = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 101:
        if ftype == TType.STRING:
          self.injected_structured_annotation_field = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 102:
        if ftype == TType.STRING:
          self.injected_unstructured_annotation_field = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeStructBegin('Fields')
    if self.injected_field != None:
      oprot.writeFieldBegin('injected_field', TType.STRING, 100)
      oprot.writeString(self.injected_field.encode('utf-8')) if UTF8STRINGS and not isinstance(self.injected_field, bytes) else oprot.writeString(self.injected_field)
      oprot.writeFieldEnd()
    if self.injected_structured_annotation_field != None:
      oprot.writeFieldBegin('injected_structured_annotation_field', TType.STRING, 101)
      oprot.writeString(self.injected_structured_annotation_field.encode('utf-8')) if UTF8STRINGS and not isinstance(self.injected_structured_annotation_field, bytes) else oprot.writeString(self.injected_structured_annotation_field)
      oprot.writeFieldEnd()
    if self.injected_unstructured_annotation_field != None:
      oprot.writeFieldBegin('injected_unstructured_annotation_field', TType.STRING, 102)
      oprot.writeString(self.injected_unstructured_annotation_field.encode('utf-8')) if UTF8STRINGS and not isinstance(self.injected_unstructured_annotation_field, bytes) else oprot.writeString(self.injected_unstructured_annotation_field)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.injected_field is not None:
      value = pprint.pformat(self.injected_field, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    injected_field=%s' % (value))
    if self.injected_structured_annotation_field is not None:
      value = pprint.pformat(self.injected_structured_annotation_field, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    injected_structured_annotation_field=%s' % (value))
    if self.injected_unstructured_annotation_field is not None:
      value = pprint.pformat(self.injected_unstructured_annotation_field, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    injected_unstructured_annotation_field=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'injected_field',
      'injected_structured_annotation_field',
      'injected_unstructured_annotation_field',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

all_structs.append(Fields)
Fields.thrift_spec = (
  None, # 0
  None, # 1
  None, # 2
  None, # 3
  None, # 4
  None, # 5
  None, # 6
  None, # 7
  None, # 8
  None, # 9
  None, # 10
  None, # 11
  None, # 12
  None, # 13
  None, # 14
  None, # 15
  None, # 16
  None, # 17
  None, # 18
  None, # 19
  None, # 20
  None, # 21
  None, # 22
  None, # 23
  None, # 24
  None, # 25
  None, # 26
  None, # 27
  None, # 28
  None, # 29
  None, # 30
  None, # 31
  None, # 32
  None, # 33
  None, # 34
  None, # 35
  None, # 36
  None, # 37
  None, # 38
  None, # 39
  None, # 40
  None, # 41
  None, # 42
  None, # 43
  None, # 44
  None, # 45
  None, # 46
  None, # 47
  None, # 48
  None, # 49
  None, # 50
  None, # 51
  None, # 52
  None, # 53
  None, # 54
  None, # 55
  None, # 56
  None, # 57
  None, # 58
  None, # 59
  None, # 60
  None, # 61
  None, # 62
  None, # 63
  None, # 64
  None, # 65
  None, # 66
  None, # 67
  None, # 68
  None, # 69
  None, # 70
  None, # 71
  None, # 72
  None, # 73
  None, # 74
  None, # 75
  None, # 76
  None, # 77
  None, # 78
  None, # 79
  None, # 80
  None, # 81
  None, # 82
  None, # 83
  None, # 84
  None, # 85
  None, # 86
  None, # 87
  None, # 88
  None, # 89
  None, # 90
  None, # 91
  None, # 92
  None, # 93
  None, # 94
  None, # 95
  None, # 96
  None, # 97
  None, # 98
  None, # 99
  (100, TType.STRING, 'injected_field', True, None, 2, ), # 100
  (101, TType.STRING, 'injected_structured_annotation_field', True, None, 1, ), # 101
  (102, TType.STRING, 'injected_unstructured_annotation_field', True, None, 1, ), # 102
)

Fields.thrift_struct_annotations = {
}
Fields.thrift_field_annotations = {
  102: {
    "thrift.box": "1",
  },
}

def Fields__init__(self, injected_field=None, injected_structured_annotation_field=None, injected_unstructured_annotation_field=None,):
  self.injected_field = injected_field
  self.injected_structured_annotation_field = injected_structured_annotation_field
  self.injected_unstructured_annotation_field = injected_unstructured_annotation_field

Fields.__init__ = Fields__init__

def Fields__setstate__(self, state):
  state.setdefault('injected_field', None)
  state.setdefault('injected_structured_annotation_field', None)
  state.setdefault('injected_unstructured_annotation_field', None)
  self.__dict__ = state

Fields.__getstate__ = lambda self: self.__dict__.copy()
Fields.__setstate__ = Fields__setstate__

fix_spec(all_structs)
del all_structs
