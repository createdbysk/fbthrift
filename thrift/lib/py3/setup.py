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
    Extension("thrift.py3.exceptions", ["exceptions.pyx"], extra_compile_args=["-fno-strict-aliasing"], language="c++", libraries=["folly"]),
    Extension("thrift.py3.server", ["server.pyx"], extra_compile_args=["-fno-strict-aliasing"], language="c++", libraries=["folly"]),
    Extension("thrift.py3.client", ["client.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.py3.reflection", ["reflection.pyx"], language="c++"),
    Extension("thrift.py3.types", ["types.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.py3.stream", ["stream.pyx", "stream.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.py3.builder", ["builder.pyx"], language="c++"),
    Extension("thrift.py3.converter", ["converter.pyx"], language="c++"),
    Extension("thrift.py3.metadata", ["metadata.pyx"], language="c++"),
    Extension("thrift.py3.test.cpp_handler", ["cpp_handler.pyx"], language="c++"),
    Extension("thrift.lib.py3.test.exception_helper", ["exception_helper.pyx"], language="c++"),
    Extension("thrift.py3.test.cpp_converter_helper", ["cpp_converter_helper.pyx"], language="c++"),
    Extension("thrift.lib.py3.test.interactions.run_interaction", ["run_interaction.pyx"], language="c++"),
    Extension("thrift.py3.test.is_overload.helper", ["helper.pyx"], language="c++"),
]

setup(
    name="thrift",
    packages=["thrift", "thrift.lib", "thrift.lib.py3", "thrift.lib.py3.test", "thrift.lib.py3.test.auto_migrate", "thrift.lib.py3.test.interactions", "thrift.py3", "thrift.py3.test", "thrift.py3.test.is_overload"],
    package_data={"": ["*.pxd", "*.h", "*.py", "*.pyi"]},
    ext_modules=cythonize(
        extensions,
        language_level=3,
        compiler_directives={"binding": True},
    ),
)