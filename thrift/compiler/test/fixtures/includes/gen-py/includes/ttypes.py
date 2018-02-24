#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from __future__ import absolute_import
import six
from thrift.util.Recursive import fix_spec
from thrift.Thrift import *
from thrift.protocol.TProtocol import TProtocolException


import transitive.ttypes


import pprint
import warnings
from thrift import Thrift
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.protocol import TCompactProtocol
from thrift.protocol import THeaderProtocol
fastproto = None
if not '__pypy__' in sys.builtin_module_names:
  try:
    from thrift.protocol import fastproto
  except:
    pass
all_structs = []
UTF8STRINGS = bool(0) or sys.version_info.major >= 3

__all__ = ['UTF8STRINGS', 'Included']

class Included:
  """
  Attributes:
   - MyIntField
   - MyTransitiveField
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
      self.checkRequired()
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2)
      self.checkRequired()
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.I64:
          self.MyIntField = iprot.readI64()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRUCT:
          self.MyTransitiveField = transitive.ttypes.Foo()
          self.MyTransitiveField.read(iprot)
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()
    self.checkRequired()

  def checkRequired(self):
    return

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeStructBegin('Included')
    if self.MyIntField != None:
      oprot.writeFieldBegin('MyIntField', TType.I64, 1)
      oprot.writeI64(self.MyIntField)
      oprot.writeFieldEnd()
    if self.MyTransitiveField != None:
      oprot.writeFieldBegin('MyTransitiveField', TType.STRUCT, 2)
      self.MyTransitiveField.write(oprot)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def __repr__(self):
    L = []
    padding = ' ' * 4
    value = pprint.pformat(self.MyIntField, indent=0)
    value = padding.join(value.splitlines(True))
    L.append('    MyIntField=%s' % (value))
    value = pprint.pformat(self.MyTransitiveField, indent=0)
    value = padding.join(value.splitlines(True))
    L.append('    MyTransitiveField=%s' % (value))
    return "%s(\n%s)" % (self.__class__.__name__, ",\n".join(L))

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  # Override the __hash__ function for Python3 - t10434117
  if not six.PY2:
    __hash__ = object.__hash__

IncludedInt64 = UnimplementedTypedef()
TransitiveFoo = transitive.ttypes.Foo
all_structs.append(Included)
Included.thrift_spec = (
  None, # 0
  (1, TType.I64, 'MyIntField', None, 0, 2, ), # 1
  (2, TType.STRUCT, 'MyTransitiveField', [transitive.ttypes.Foo, transitive.ttypes.Foo.thrift_spec, False], transitive.ttypes.Foo(**{
    "a" : 2,
  }), 2, ), # 2
)

Included.thrift_struct_annotations = {
}
Included.thrift_field_annotations = {
}

def Included__init__(self, MyIntField=Included.thrift_spec[1][4], MyTransitiveField=Included.thrift_spec[2][4],):
  self.MyIntField = MyIntField
  if MyTransitiveField is self.thrift_spec[2][4]:
    MyTransitiveField = transitive.ttypes.Foo(**{
    "a" : 2,
  })
  self.MyTransitiveField = MyTransitiveField

Included.__init__ = Included__init__

def Included__setstate__(self, state):
  state.setdefault('MyIntField', 0)
  state.setdefault('MyTransitiveField', transitive.ttypes.Foo(**{
    "a" : 2,
  }))
  self.__dict__ = state

Included.__getstate__ = lambda self: self.__dict__.copy()
Included.__setstate__ = Included__setstate__

fix_spec(all_structs)
del all_structs
