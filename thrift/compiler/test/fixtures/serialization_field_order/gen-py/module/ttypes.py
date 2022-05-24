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

from json import loads
import sys
if sys.version_info[0] >= 3:
  long = int

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

__all__ = ['UTF8STRINGS', 'Foo', 'Foo2']

class Foo:
  """
  Attributes:
   - field1
   - field2
   - field3
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
      if fid == 3:
        if ftype == TType.I32:
          self.field1 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 1:
        if ftype == TType.I32:
          self.field2 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.I32:
          self.field3 = iprot.readI32()
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
    oprot.writeStructBegin('Foo')
    if self.field2 != None:
      oprot.writeFieldBegin('field2', TType.I32, 1)
      oprot.writeI32(self.field2)
      oprot.writeFieldEnd()
    if self.field3 != None:
      oprot.writeFieldBegin('field3', TType.I32, 2)
      oprot.writeI32(self.field3)
      oprot.writeFieldEnd()
    if self.field1 != None:
      oprot.writeFieldBegin('field1', TType.I32, 3)
      oprot.writeI32(self.field1)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'field1' in json_obj and json_obj['field1'] is not None:
      self.field1 = json_obj['field1']
      if self.field1 > 0x7fffffff or self.field1 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'field2' in json_obj and json_obj['field2'] is not None:
      self.field2 = json_obj['field2']
      if self.field2 > 0x7fffffff or self.field2 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'field3' in json_obj and json_obj['field3'] is not None:
      self.field3 = json_obj['field3']
      if self.field3 > 0x7fffffff or self.field3 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.field1 is not None:
      value = pprint.pformat(self.field1, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field1=%s' % (value))
    if self.field2 is not None:
      value = pprint.pformat(self.field2, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field2=%s' % (value))
    if self.field3 is not None:
      value = pprint.pformat(self.field3, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field3=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'field2',
      'field3',
      'field1',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

class Foo2:
  """
  Attributes:
   - field1
   - field2
   - field3
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
      if fid == 3:
        if ftype == TType.I32:
          self.field1 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 1:
        if ftype == TType.I32:
          self.field2 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.I32:
          self.field3 = iprot.readI32()
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
    oprot.writeStructBegin('Foo2')
    if self.field2 != None:
      oprot.writeFieldBegin('field2', TType.I32, 1)
      oprot.writeI32(self.field2)
      oprot.writeFieldEnd()
    if self.field3 != None:
      oprot.writeFieldBegin('field3', TType.I32, 2)
      oprot.writeI32(self.field3)
      oprot.writeFieldEnd()
    if self.field1 != None:
      oprot.writeFieldBegin('field1', TType.I32, 3)
      oprot.writeI32(self.field1)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'field1' in json_obj and json_obj['field1'] is not None:
      self.field1 = json_obj['field1']
      if self.field1 > 0x7fffffff or self.field1 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'field2' in json_obj and json_obj['field2'] is not None:
      self.field2 = json_obj['field2']
      if self.field2 > 0x7fffffff or self.field2 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'field3' in json_obj and json_obj['field3'] is not None:
      self.field3 = json_obj['field3']
      if self.field3 > 0x7fffffff or self.field3 < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.field1 is not None:
      value = pprint.pformat(self.field1, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field1=%s' % (value))
    if self.field2 is not None:
      value = pprint.pformat(self.field2, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field2=%s' % (value))
    if self.field3 is not None:
      value = pprint.pformat(self.field3, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    field3=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'field2',
      'field3',
      'field1',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

all_structs.append(Foo)
Foo.thrift_spec = (
  None, # 0
  (1, TType.I32, 'field2', None, None, 2, ), # 1
  (2, TType.I32, 'field3', None, None, 2, ), # 2
  (3, TType.I32, 'field1', None, None, 2, ), # 3
)

Foo.thrift_struct_annotations = {
}
Foo.thrift_field_annotations = {
}

def Foo__init__(self, field1=None, field2=None, field3=None,):
  self.field1 = field1
  self.field2 = field2
  self.field3 = field3

Foo.__init__ = Foo__init__

def Foo__setstate__(self, state):
  state.setdefault('field1', None)
  state.setdefault('field2', None)
  state.setdefault('field3', None)
  self.__dict__ = state

Foo.__getstate__ = lambda self: self.__dict__.copy()
Foo.__setstate__ = Foo__setstate__

all_structs.append(Foo2)
Foo2.thrift_spec = (
  None, # 0
  (1, TType.I32, 'field2', None, None, 2, ), # 1
  (2, TType.I32, 'field3', None, None, 2, ), # 2
  (3, TType.I32, 'field1', None, None, 2, ), # 3
)

Foo2.thrift_struct_annotations = {
}
Foo2.thrift_field_annotations = {
}

def Foo2__init__(self, field1=None, field2=None, field3=None,):
  self.field1 = field1
  self.field2 = field2
  self.field3 = field3

Foo2.__init__ = Foo2__init__

def Foo2__setstate__(self, state):
  state.setdefault('field1', None)
  state.setdefault('field2', None)
  state.setdefault('field3', None)
  self.__dict__ = state

Foo2.__getstate__ = lambda self: self.__dict__.copy()
Foo2.__setstate__ = Foo2__setstate__

fix_spec(all_structs)
del all_structs
