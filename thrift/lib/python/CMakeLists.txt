# Auto-generated from Buck TARGETS by buck_to_cmake_generator.py
# This file is designed to be used with add_subdirectory()
# Parent CMakeLists.txt must provide:
#   - Python3 (via find_package)
#   - _cybld variable (build output directory)


# Create package directory structure
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/client/test/client_event_handler)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/server)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/server/interceptor)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/streaming)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/test/event_handlers)
file(MAKE_DIRECTORY ${_cybld}/thrift/python)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/any)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/capi)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/client)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/conformance)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/marshal)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/server_impl)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/server_impl/interceptor)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/streaming)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/test/request_context_extractor)

# Target for Cython API generation (--api-only phase)
add_custom_target(python_cython_api_generation ALL
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py --api-only
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Generating Cython API headers"
)

# Auto-generated symlinks from Buck→CMake generator
add_custom_target(python_create_cython_api_symlinks ALL
  DEPENDS python_cython_api_generation
)

# types (package=thrift.python)

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/types_api.h"
    "${_cybld}/thrift/lib/python/types_api.h"
)

# python_async_processor (package=thrift.python.server_impl)
# cpp_compiler_flags: ['-D__PYX_ENUM_CLASS_DECL=']

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/server_impl/python_async_processor_api.h"
    "${_cybld}/thrift/lib/python/server/python_async_processor_api.h"
)

# py_promise (package=thrift.python.streaming)

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/streaming/py_promise_api.h"
    "${_cybld}/thrift/lib/python/streaming/py_promise_api.h"
)

# sink (package=thrift.python.streaming)

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/streaming/sink_api.h"
    "${_cybld}/thrift/lib/python/streaming/sink_api.h"
)

# bidistream (package=thrift.python.streaming)

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/streaming/bidistream_api.h"
    "${_cybld}/thrift/lib/python/streaming/bidistream_api.h"
)

# service_interceptor (package=thrift.python.server_impl.interceptor)

add_custom_command(TARGET python_create_cython_api_symlinks
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/server_impl/interceptor/service_interceptor_api.h"
    "${_cybld}/thrift/lib/python/server/interceptor/service_interceptor_api.h"
)

# Target for Cython compilation (build_ext phase)
add_custom_target(python_cython_build_ext ALL
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py build_ext --inplace
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS python_create_cython_api_symlinks
  COMMENT "Building Cython extensions"
)

# Buck parameters for all targets:

# std_libcpp:
#   package: thrift.python
#   header_namespace: thrift/lib/python

# common:
#   package: thrift.python
#   header_namespace: thrift/lib/python

# types:
#   package: thrift.python
#   header_namespace: thrift/lib/python
#   api: ['types']

# protocol:
#   package: thrift.python

# converter:
#   package: thrift.python

# mutable_types:
#   package: thrift.python
#   api: ['mutable_types']

# mutable_converter:
#   package: thrift.python

# serializer:
#   package: thrift.python.any

# cpp_converter:
#   package: thrift.python.capi

# omni_client:
#   package: thrift.python.client

# request_channel:
#   package: thrift.python.client

# ssl:
#   package: thrift.python.client

# sync_client:
#   package: thrift.python.client

# sync_channel_factory:
#   package: thrift.python.client

# sync_client_factory:
#   package: thrift.python.client

# async_client:
#   package: thrift.python.client

# async_client_factory:
#   package: thrift.python.client

# universal_name:
#   package: thrift.python.conformance

# async_processor:
#   package: thrift.python.server_impl

# event_handler:
#   package: thrift.python.server_impl

# request_context:
#   package: thrift.python.server_impl
#   api: ['request_context']

# python_async_processor:
#   package: thrift.python.server_impl
#   header_namespace: thrift/lib/python/server
#   api: ['python_async_processor']
#   cpp_compiler_flags: ['-D__PYX_ENUM_CLASS_DECL=']

# server:
#   package: thrift.python

# py_promise:
#   package: thrift.python.streaming
#   header_namespace: thrift/lib/python/streaming
#   api: ['py_promise']

# python_user_exception:
#   package: thrift.python.streaming

# sink:
#   package: thrift.python.streaming
#   header_namespace: thrift/lib/python/streaming
#   api: ['sink']

# stream:
#   package: thrift.python.streaming

# bidistream:
#   package: thrift.python.streaming
#   header_namespace: thrift/lib/python/streaming
#   api: ['bidistream']

# typeinfo_ctest:
#   package: thrift.python.test

# marshal_fixture:
#   package: thrift.python.marshal

# client:
#   package: thrift.lib.python.client.test.client_event_handler

# server_module:
#   package: thrift.python.server_impl.interceptor

# service_interceptor:
#   package: thrift.python.server_impl.interceptor
#   header_namespace: thrift/lib/python/server/interceptor
#   api: ['service_interceptor']

# python_async_processor_factory_ctest:
#   package: thrift.python.test

# cpp_converter_helper:
#   package: thrift.python.test

# handler:
#   package: thrift.lib.python.test.event_handlers

# request_context_extractor:
#   package: thrift.python.test.request_context_extractor