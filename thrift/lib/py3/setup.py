#!/usr/bin/env python3
"""Auto-generated setup.py from Buck TARGETS"""

import sys
from Cython.Build import cythonize
from Cython.Compiler import Options, Main as CythonMain
from setuptools import setup, Extension

if "--api-only" in sys.argv:
    print("Generating Cython API headers...")
    print(f"  thrift.py3.stream (api)")
    CythonMain.compile(
        "stream.pyx",
        full_module_name="thrift.py3.stream",
        cplus=True,
        language_level=3,
    )
    sys.exit(0)

# Build extensions
extensions = [
    Extension("thrift.py3.exceptions", ["exceptions.pyx"], extra_compile_args=["-fno-strict-aliasing"]),
    Extension("thrift.py3.server", ["server.pyx"], extra_compile_args=["-fno-strict-aliasing", ""]),
    Extension("thrift.py3.client", ["client.pyx"]),
    Extension("thrift.py3.reflection", ["reflection.pyx"]),
    Extension("thrift.py3.serializer", ["serializer.pyx"]),
    Extension("thrift.py3.types", ["types.pyx"]),
    Extension("thrift.py3.stream", ["stream.pyx"]),
    Extension("thrift.py3.builder", ["builder.pyx"]),
    Extension("thrift.py3.converter", ["converter.pyx"]),
    Extension("thrift.py3.metadata", ["metadata.pyx"]),
    Extension("thrift.py3.test.cpp_handler", ["cpp_handler.pyx"]),
    Extension("thrift.py3.test.cpp_converter_helper", ["cpp_converter_helper.pyx"]),
    Extension("thrift.py3.test.is_overload.helper", ["helper.pyx"]),
]

setup(
    name="thrift",
    ext_modules=cythonize(
        extensions,
        language_level=3,
        compiler_directives={"binding": True},
    ),
)