#!/usr/bin/env python3
"""Auto-generated setup.py from Buck TARGETS"""

import os
import sys
from pathlib import Path
from Cython.Build import cythonize
from Cython.Compiler import Options, Main as CythonMain
from setuptools import setup, Extension

# Validate CYTHON_INCLUDE_PATH from CMakeLists.txt
cython_include_path = os.environ.get("CYTHON_INCLUDE_PATH")
if not cython_include_path:
    raise RuntimeError(
        "CYTHON_INCLUDE_PATH environment variable not set. "
        "This should be set by CMakeLists.txt to the cybld directory."
    )

include_dirs = [p for p in cython_include_path.split(":") if p]
if not include_dirs:
    raise RuntimeError(
        f"CYTHON_INCLUDE_PATH is empty: {cython_include_path!r}"
    )

# Validate paths exist
for include_dir in include_dirs:
    if not Path(include_dir).exists():
        raise RuntimeError(
            f"CYTHON_INCLUDE_PATH contains non-existent directory: {include_dir}\n"
            f"Full path: {cython_include_path}"
        )

if "--api-only" in sys.argv:
    print("Generating Cython API headers...")

    # Create CompilationOptions with include_path for cimport resolution
    compilation_options = Options.CompilationOptions(
        Options.default_options,
        include_path=include_dirs,
    )

    print(f"  thrift.python.types (api)")
    CythonMain.compile(
        "types.pyx",
        options=compilation_options,
        full_module_name="thrift.python.types",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.mutable_types (api)")
    CythonMain.compile(
        "mutable_types.pyx",
        options=compilation_options,
        full_module_name="thrift.python.mutable_types",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.request_context (api)")
    CythonMain.compile(
        "request_context.pyx",
        options=compilation_options,
        full_module_name="thrift.python.server_impl.request_context",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.python_async_processor (api)")
    CythonMain.compile(
        "python_async_processor.pyx",
        options=compilation_options,
        full_module_name="thrift.python.server_impl.python_async_processor",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.py_promise (api)")
    CythonMain.compile(
        "py_promise.pyx",
        options=compilation_options,
        full_module_name="thrift.python.streaming.py_promise",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.sink (api)")
    CythonMain.compile(
        "sink.pyx",
        options=compilation_options,
        full_module_name="thrift.python.streaming.sink",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.streaming.bidistream (api)")
    CythonMain.compile(
        "bidistream.pyx",
        options=compilation_options,
        full_module_name="thrift.python.streaming.bidistream",
        cplus=True,
        language_level=3,
    )
    print(f"  thrift.python.server_impl.interceptor.service_interceptor (api)")
    CythonMain.compile(
        "service_interceptor.pyx",
        options=compilation_options,
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
    Extension("thrift.python.any.serializer", ["any/serializer.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.omni_client", ["client/omni_client.pyx", "client/OmniClient.cpp"], language="c++", libraries=["fmt", "folly"]),
    Extension("thrift.python.client.request_channel", ["client/request_channel.pyx", "client/RequestChannel.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.ssl", ["client/ssl.pyx", "client/ssl.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.client.sync_client", ["client/sync_client.pyx"], language="c++"),
    Extension("thrift.python.client.sync_channel_factory", ["client/sync_channel_factory.pyx"], language="c++"),
    Extension("thrift.python.client.sync_client_factory", ["client/sync_client_factory.pyx"], language="c++"),
    Extension("thrift.python.client.async_client", ["client/async_client.pyx"], language="c++"),
    Extension("thrift.python.client.async_client_factory", ["client/async_client_factory.pyx"], language="c++"),
    Extension("thrift.python.conformance.universal_name", ["conformance/universal_name.pyx"], language="c++"),
    Extension("thrift.python.server_impl.async_processor", ["server/async_processor.pyx"], language="c++"),
    Extension("thrift.python.server_impl.request_context", ["server/request_context.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.server_impl.python_async_processor", ["server/python_async_processor.pyx", "server/PythonAsyncProcessor.cpp", "server/PythonAsyncProcessorFactory.cpp"], extra_compile_args=["-D__PYX_ENUM_CLASS_DECL="], language="c++", libraries=["folly"]),
    Extension("thrift.python.server", ["server/server.pyx"], language="c++"),
    Extension("thrift.python.streaming.py_promise", ["streaming/py_promise.pyx"], language="c++"),
    Extension("thrift.python.streaming.python_user_exception", ["streaming/python_user_exception.pyx"], language="c++"),
    Extension("thrift.python.streaming.sink", ["streaming/sink.pyx", "streaming/Sink.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.streaming.stream", ["streaming/stream.pyx"], language="c++"),
    Extension("thrift.python.streaming.bidistream", ["streaming/bidistream.pyx", "streaming/bidistream.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.typeinfo_test", ["test/typeinfo_test.pyx"], language="c++"),
    Extension("thrift.python.marshal.marshal_fixture", ["capi/test/marshal_fixture.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.exceptions_helper", ["client/test/exceptions_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.event_handler_helper", ["client/test/event_handler_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.client.test.http2_helper", ["client/test/http2_helper.pyx"], language="c++", libraries=["proxygen"]),
    Extension("thrift.lib.python.client.test.client_event_handler.helper", ["client/test/client_event_handlers/helper.pyx"], language="c++"),
    Extension("thrift.python.server_impl.interceptor.server_module", ["server/interceptor/server_module.pyx"], language="c++"),
    Extension("thrift.python.server_impl.interceptor.service_interceptor", ["server/interceptor/service_interceptor.pyx", "server/interceptor/PythonServiceInterceptor.cpp"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.python_async_processor_factory_test", ["server/test/python_async_processor_factory_test.pyx"], language="c++"),
    Extension("thrift.python.test.cpp_converter_helper", ["test/cpp_conversion/cpp_converter_helper.pyx"], language="c++"),
    Extension("thrift.lib.python.test.event_handlers.helper", ["test/event_handlers/helper.pyx"], language="c++"),
    Extension("thrift.lib.python.test.interactions.run_interaction", ["test/interactions/run_interaction.pyx"], language="c++"),
    Extension("thrift.lib.python.test.metadata_response.metadata_response", ["test/metadata_response/metadata_response.pyx"], language="c++", libraries=["folly"]),
    Extension("thrift.python.test.request_context_extractor.request_context_extractor", ["test/request_context_extractor/request_context_extractor.pyx"], language="c++", libraries=["folly"]),
]

setup(
    name="thrift",
    packages=["thrift", "thrift.lib", "thrift.lib.python", "thrift.lib.python.any", "thrift.lib.python.benchmark", "thrift.lib.python.client", "thrift.lib.python.client.test", "thrift.lib.python.client.test.client_event_handler", "thrift.lib.python.conformance", "thrift.lib.python.server", "thrift.lib.python.server.interceptor", "thrift.lib.python.server.interceptor.test", "thrift.lib.python.test", "thrift.lib.python.test.event_handlers", "thrift.lib.python.test.interactions", "thrift.lib.python.test.metadata_response", "thrift.python", "thrift.python.any", "thrift.python.capi", "thrift.python.client", "thrift.python.conformance", "thrift.python.marshal", "thrift.python.server_impl", "thrift.python.server_impl.interceptor", "thrift.python.streaming", "thrift.python.test", "thrift.python.test.adapters", "thrift.python.test.request_context_extractor"],
    package_data={"": ["*.pxd", "*.h", "*.py", "*.pyi"]},
    ext_modules=cythonize(
        extensions,
        language_level=3,
        compiler_directives={"binding": True},
        include_path=include_dirs,  # Allow cimport to find .pxd files
    ),
)