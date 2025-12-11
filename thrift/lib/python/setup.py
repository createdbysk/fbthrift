#!/usr/bin/env python3
"""Auto-generated setup.py from Buck TARGETS"""

import sys
from Cython.Build import cythonize
from Cython.Compiler import Options, Main as CythonMain
from setuptools import setup, Extension

if "--api-only" in sys.argv:
    print("Generating Cython API headers...")
    print(f"  thrift.python.adapter (api)")
    CythonMain.compile(
        "adapter.pyx",
        full_module_name="thrift.python.adapter",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.exceptions (api)")
    CythonMain.compile(
        "exceptions.pyx",
        full_module_name="thrift.python.exceptions",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.serializer (api)")
    CythonMain.compile(
        "serializer.pyx",
        full_module_name="thrift.python.serializer",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.types (api)")
    CythonMain.compile(
        "types.pyx",
        full_module_name="thrift.python.types",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_containers (api)")
    CythonMain.compile(
        "mutable_containers.pyx",
        full_module_name="thrift.python.mutable_containers",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_exceptions (api)")
    CythonMain.compile(
        "mutable_exceptions.pyx",
        full_module_name="thrift.python.mutable_exceptions",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_serializer (api)")
    CythonMain.compile(
        "mutable_serializer.pyx",
        full_module_name="thrift.python.mutable_serializer",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_typeinfos (api)")
    CythonMain.compile(
        "mutable_typeinfos.pyx",
        full_module_name="thrift.python.mutable_typeinfos",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_types (api)")
    CythonMain.compile(
        "mutable_types.pyx",
        full_module_name="thrift.python.mutable_types",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.request_context (api)")
    CythonMain.compile(
        "request_context.pyx",
        full_module_name="thrift.python.server_impl.request_context",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.python_async_processor (api)")
    CythonMain.compile(
        "python_async_processor.pyx",
        full_module_name="thrift.python.server_impl.python_async_processor",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.py_promise (api)")
    CythonMain.compile(
        "py_promise.pyx",
        full_module_name="thrift.python.streaming.py_promise",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.sink (api)")
    CythonMain.compile(
        "sink.pyx",
        full_module_name="thrift.python.streaming.sink",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.bidistream (api)")
    CythonMain.compile(
        "bidistream.pyx",
        full_module_name="thrift.python.streaming.bidistream",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.interceptor.service_interceptor (api)")
    CythonMain.compile(
        "service_interceptor.pyx",
        full_module_name="thrift.python.server_impl.interceptor.service_interceptor",
        cplus=True,
        language_level=3,
    )
    sys.exit(0)

# Build extensions
extensions = [
    Extension("thrift.python.common", ["common.pyx"]),
    Extension("thrift.python.adapter", ["adapter.pyx"]),
    Extension("thrift.python.exceptions", ["exceptions.pyx"]),
    Extension("thrift.python.serializer", ["serializer.pyx"]),
    Extension("thrift.python.types", ["types.pyx"]),
    Extension("thrift.python.protocol", ["protocol.pyx"]),
    Extension("thrift.python.converter", ["converter.pyx"]),
    Extension("thrift.python.mutable_containers", ["mutable_containers.pyx"]),
    Extension("thrift.python.mutable_exceptions", ["mutable_exceptions.pyx"]),
    Extension("thrift.python.mutable_serializer", ["mutable_serializer.pyx"]),
    Extension("thrift.python.mutable_typeinfos", ["mutable_typeinfos.pyx"]),
    Extension("thrift.python.mutable_types", ["mutable_types.pyx"]),
    Extension("thrift.python.mutable_converter", ["mutable_converter.pyx"]),
    Extension("thrift.python.any.serializer", ["serializer.pyx"]),
    Extension("thrift.python.client.omni_client", ["omni_client.pyx"]),
    Extension("thrift.python.client.request_channel", ["request_channel.pyx"]),
    Extension("thrift.python.client.ssl", ["ssl.pyx"]),
    Extension("thrift.python.client.sync_client", ["sync_client.pyx"]),
    Extension("thrift.python.client.sync_channel_factory", ["sync_channel_factory.pyx"]),
    Extension("thrift.python.client.sync_client_factory", ["sync_client_factory.pyx"]),
    Extension("thrift.python.client.async_client", ["async_client.pyx"]),
    Extension("thrift.python.client.async_client_factory", ["async_client_factory.pyx"]),
    Extension("thrift.python.conformance.universal_name", ["universal_name.pyx"]),
    Extension("thrift.python.server_impl.async_processor", ["async_processor.pyx"]),
    Extension("thrift.python.server_impl.request_context", ["request_context.pyx"]),
    Extension("thrift.python.server_impl.python_async_processor", ["python_async_processor.pyx"], extra_compile_args=["-D__PYX_ENUM_CLASS_DECL="]),
    Extension("thrift.python.server", ["server.pyx"]),
    Extension("thrift.python.streaming.py_promise", ["py_promise.pyx"]),
    Extension("thrift.python.streaming.python_user_exception", ["python_user_exception.pyx"]),
    Extension("thrift.python.streaming.sink", ["sink.pyx"]),
    Extension("thrift.python.streaming.stream", ["stream.pyx"]),
    Extension("thrift.python.streaming.bidistream", ["bidistream.pyx"]),
    Extension("thrift.python.test.typeinfo_test", ["typeinfo_test.pyx"]),
    Extension("thrift.python.marshal.marshal_fixture", ["marshal_fixture.pyx"]),
    Extension("thrift.lib.python.client.test.client_event_handler.helper", ["helper.pyx"]),
    Extension("thrift.python.server_impl.interceptor.server_module", ["server_module.pyx"]),
    Extension("thrift.python.server_impl.interceptor.service_interceptor", ["service_interceptor.pyx"]),
    Extension("thrift.python.test.python_async_processor_factory_test", ["python_async_processor_factory_test.pyx"]),
    Extension("thrift.python.test.cpp_converter_helper", ["cpp_converter_helper.pyx"]),
    Extension("thrift.lib.python.test.event_handlers.helper", ["helper.pyx"]),
    Extension("thrift.python.test.request_context_extractor.request_context_extractor", ["request_context_extractor.pyx"]),
]

setup(
    name="thrift",
    ext_modules=cythonize(
        extensions,
        language_level=3,
        compiler_directives={"binding": True},
    ),
)