#!/usr/bin/env python3
"""Auto-generated setup.py from Buck TARGETS"""

import sys
from Cython.Build import cythonize
from Cython.Compiler import Options, Main as CythonMain
from setuptools import setup, Extension

if "--api-only" in sys.argv:
    print("Generating Cython API headers...")
    print(f"  thrift.python.types (api)")
    CythonMain.compile(
        "types.pyx",
        full_module_name="thrift.python.types",
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
    Extension("thrift.python.common", ["common.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.types", ["types.pyx", "Serializer.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.protocol", ["protocol.pyx"], language="c++"),
    Extension("thrift.python.converter", ["converter.pyx"], language="c++"),
    Extension("thrift.python.mutable_types", ["mutable_types.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.mutable_converter", ["mutable_converter.pyx"], language="c++"),
    Extension("thrift.python.any.serializer", ["serializer.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.omni_client", ["omni_client.pyx", "OmniClient.cpp"], language="c++", libraries=["fmt", "folly"]),
    Extension("thrift.python.client.request_channel", ["request_channel.pyx", "RequestChannel.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.ssl", ["ssl.pyx", "ssl.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.sync_client", ["sync_client.pyx"], language="c++"),
    Extension("thrift.python.client.sync_channel_factory", ["sync_channel_factory.pyx"], language="c++"),
    Extension("thrift.python.client.sync_client_factory", ["sync_client_factory.pyx"], language="c++"),
    Extension("thrift.python.client.async_client", ["async_client.pyx"], language="c++"),
    Extension("thrift.python.client.async_client_factory", ["async_client_factory.pyx"], language="c++"),
    Extension("thrift.python.conformance.universal_name", ["universal_name.pyx"], language="c++"),
    Extension("thrift.python.server_impl.async_processor", ["async_processor.pyx"], language="c++"),
    Extension("thrift.python.server_impl.request_context", ["request_context.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.server_impl.python_async_processor", ["python_async_processor.pyx", "PythonAsyncProcessor.cpp", "PythonAsyncProcessorFactory.cpp"], extra_compile_args=["-D__PYX_ENUM_CLASS_DECL="], language="c++", libraries=["folly"]),
    Extension("thrift.python.server", ["server.pyx"], language="c++"),
    Extension("thrift.python.streaming.py_promise", ["py_promise.pyx"], language="c++"),
    Extension("thrift.python.streaming.python_user_exception", ["python_user_exception.pyx"], language="c++"),
    Extension("thrift.python.streaming.sink", ["sink.pyx", "Sink.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.streaming.stream", ["stream.pyx"], language="c++"),
    Extension("thrift.python.streaming.bidistream", ["bidistream.pyx", "bidistream.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.typeinfo_test", ["typeinfo_test.pyx"], language="c++"),
    Extension("thrift.python.marshal.marshal_fixture", ["marshal_fixture.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.exceptions_helper", ["exceptions_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.event_handler_helper", ["event_handler_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.http2_helper", ["http2_helper.pyx"], language="c++", libraries=["proxygen"]),
    Extension("thrift.lib.python.client.test.client_event_handler.helper", ["helper.pyx"], language="c++"),
    Extension("thrift.python.server_impl.interceptor.server_module", ["server_module.pyx"], language="c++"),
    Extension("thrift.python.server_impl.interceptor.service_interceptor", ["service_interceptor.pyx", "PythonServiceInterceptor.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.python_async_processor_factory_test", ["python_async_processor_factory_test.pyx"], language="c++"),
    Extension("thrift.python.test.cpp_converter_helper", ["cpp_converter_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.test.event_handlers.helper", ["helper.pyx"], language="c++"),
    Extension("thrift.lib.python.test.interactions.run_interaction", ["run_interaction.pyx"], language="c++"),
    Extension("thrift.lib.python.test.metadata_response.metadata_response", ["metadata_response.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.request_context_extractor.request_context_extractor", ["request_context_extractor.pyx"], language="c++", libraries=["folly"]),
]

setup(
    name="thrift",
    packages=["thrift", "thrift.lib", "thrift.lib.python", "thrift.lib.python.any", "thrift.lib.python.benchmark", "thrift.lib.python.client", "thrift.lib.python.client.test", "thrift.lib.python.client.test.client_event_handler", "thrift.lib.python.conformance", "thrift.lib.python.server", "thrift.lib.python.server.interceptor", "thrift.lib.python.server.interceptor.test", "thrift.lib.python.test", "thrift.lib.python.test.event_handlers", "thrift.lib.python.test.interactions", "thrift.lib.python.test.metadata_response", "thrift.python", "thrift.python.any", "thrift.python.capi", "thrift.python.client", "thrift.python.conformance", "thrift.python.marshal", "thrift.python.server_impl", "thrift.python.server_impl.interceptor", "thrift.python.streaming", "thrift.python.test", "thrift.python.test.adapters", "thrift.python.test.request_context_extractor"],
    package_data={"": ["*.pxd", "*.h", "*.py", "*.pyi"]},
    ext_modules=cythonize(
        extensions,
        language_level=3,
        compiler_directives={"binding": True},
    ),
)