#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/py3/src/empty.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection import (
  ArgumentSpec as __ArgumentSpec,
  InterfaceSpec as __InterfaceSpec,
  MethodSpec as __MethodSpec,
  NumberType as __NumberType,
)

import folly.iobuf as _fbthrift_iobuf


import empty.types as _empty_types


def get_reflection__NullService(for_clients: bool):
    spec: __InterfaceSpec = __InterfaceSpec(
        name="NullService",
        methods=None,
        annotations={
        },
    )
    return spec