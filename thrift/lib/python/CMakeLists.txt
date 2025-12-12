# Auto-generated from Buck TARGETS by buck_to_cmake_generator.py
# This file is designed to be used with add_subdirectory()
# Parent CMakeLists.txt must provide:
#   - Python3 (via find_package)
#   - _cybld variable (build output directory)


# Create package directory structure
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/any)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/benchmark)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/client/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/client/test/client_event_handler)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/conformance)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/server/interceptor/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/test/event_handlers)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/test/interactions)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/python/test/metadata_response)
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
file(MAKE_DIRECTORY ${_cybld}/thrift/python/test/adapters)
file(MAKE_DIRECTORY ${_cybld}/thrift/python/test/request_context_extractor)

# Create package directories in source tree for setup.py --inplace
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/any)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/benchmark)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/client/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/client/test/client_event_handler)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/conformance)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/server/interceptor/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/test/event_handlers)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/test/interactions)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/python/test/metadata_response)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/any)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/capi)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/client)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/conformance)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/marshal)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/server_impl)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/server_impl/interceptor)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/streaming)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/test/adapters)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/python/test/request_context_extractor)

# Create source file directory structure
file(MAKE_DIRECTORY ${_cybld}/any)
file(MAKE_DIRECTORY ${_cybld}/capi)
file(MAKE_DIRECTORY ${_cybld}/capi/test)
file(MAKE_DIRECTORY ${_cybld}/client)
file(MAKE_DIRECTORY ${_cybld}/client/test)
file(MAKE_DIRECTORY ${_cybld}/client/test/client_event_handlers)
file(MAKE_DIRECTORY ${_cybld}/conformance)
file(MAKE_DIRECTORY ${_cybld}/server)
file(MAKE_DIRECTORY ${_cybld}/server/interceptor)
file(MAKE_DIRECTORY ${_cybld}/server/test)
file(MAKE_DIRECTORY ${_cybld}/streaming)
file(MAKE_DIRECTORY ${_cybld}/test)
file(MAKE_DIRECTORY ${_cybld}/test/cpp_conversion)
file(MAKE_DIRECTORY ${_cybld}/test/event_handlers)
file(MAKE_DIRECTORY ${_cybld}/test/interactions)
file(MAKE_DIRECTORY ${_cybld}/test/metadata_response)
file(MAKE_DIRECTORY ${_cybld}/test/request_context_extractor)

# Symlink .pxd files from external dependencies
# Generated automatically from Buck cpp_deps

# fmt
file(MAKE_DIRECTORY "${_cybld}/fmt/")
file(GLOB _fmt_pxd_files "${fmt_INCLUDE_DIR}/fmt/*.pxd")
foreach(_pxd ${_fmt_pxd_files})
  get_filename_component(_pxd_name "${_pxd}" NAME)
  file(CREATE_LINK "${_pxd}" "${_cybld}/fmt/${_pxd_name}" SYMBOLIC)
endforeach()

# folly
file(MAKE_DIRECTORY "${_cybld}/folly/")
file(GLOB _folly_pxd_files "${FOLLY_INCLUDE_DIR}/folly/*.pxd")
foreach(_pxd ${_folly_pxd_files})
  get_filename_component(_pxd_name "${_pxd}" NAME)
  file(CREATE_LINK "${_pxd}" "${_cybld}/folly/${_pxd_name}" SYMBOLIC)
endforeach()

# proxygen
file(MAKE_DIRECTORY "${_cybld}/proxygen/")
file(GLOB _proxygen_pxd_files "${PROXYGEN_INCLUDE_DIR}/proxygen/*.pxd")
foreach(_pxd ${_proxygen_pxd_files})
  get_filename_component(_pxd_name "${_pxd}" NAME)
  file(CREATE_LINK "${_pxd}" "${_cybld}/proxygen/${_pxd_name}" SYMBOLIC)
endforeach()


# Symlink Python library files

add_custom_command(OUTPUT ${_cybld}/thrift/python/abstract_types.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/abstract_types.py
    ${_cybld}/thrift/python/abstract_types.py
  COMMENT "Symlinking abstract_types.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/metadata.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/metadata.py
    ${_cybld}/thrift/python/metadata.py
  COMMENT "Symlinking metadata.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/metadata.pyi
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/metadata.pyi
    ${_cybld}/thrift/python/metadata.pyi
  COMMENT "Symlinking metadata.pyi"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test_helpers.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test_helpers.py
    ${_cybld}/thrift/python/test_helpers.py
  COMMENT "Symlinking test_helpers.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/any/typestub.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/any/typestub.py
    ${_cybld}/thrift/lib/python/any/typestub.py
  COMMENT "Symlinking typestub.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/any/any_registry.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/any/any_registry.py
    ${_cybld}/thrift/lib/python/any/any_registry.py
  COMMENT "Symlinking any_registry.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/benchmark/benchmark_struct.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/benchmark_struct.py
    ${_cybld}/thrift/lib/python/benchmark/benchmark_struct.py
  COMMENT "Symlinking benchmark_struct.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/benchmark/containers.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/containers.py
    ${_cybld}/thrift/lib/python/benchmark/containers.py
  COMMENT "Symlinking containers.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/benchmark/struct_memory.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/struct_memory.py
    ${_cybld}/thrift/lib/python/benchmark/struct_memory.py
  COMMENT "Symlinking struct_memory.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/client_wrapper.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/client_wrapper.py
    ${_cybld}/thrift/python/client/client_wrapper.py
  COMMENT "Symlinking client_wrapper.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/__init__.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/__init__.py
    ${_cybld}/thrift/python/client/__init__.py
  COMMENT "Symlinking __init__.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/conformance/any_registry.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/conformance/any_registry.py
    ${_cybld}/thrift/lib/python/conformance/any_registry.py
  COMMENT "Symlinking any_registry.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/test/test_server.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/test_server.py
    ${_cybld}/thrift/lib/python/test/test_server.py
  COMMENT "Symlinking test_server.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/test/testing_utils.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/testing_utils.py
    ${_cybld}/thrift/lib/python/test/testing_utils.py
  COMMENT "Symlinking testing_utils.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/client/test/test_server.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/test_server.py
    ${_cybld}/thrift/lib/python/client/test/test_server.py
  COMMENT "Symlinking test_server.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/server/interceptor/test/interceptors.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/test/interceptors.py
    ${_cybld}/thrift/lib/python/server/interceptor/test/interceptors.py
  COMMENT "Symlinking interceptors.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test/adapters/datetime.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/adapters/datetime.py
    ${_cybld}/thrift/python/test/adapters/datetime.py
  COMMENT "Symlinking datetime.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test/adapters/atoi.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/adapters/atoi.py
    ${_cybld}/thrift/python/test/adapters/atoi.py
  COMMENT "Symlinking atoi.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test/adapters/noop.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/adapters/noop.py
    ${_cybld}/thrift/python/test/adapters/noop.py
  COMMENT "Symlinking noop.py"
)

# Target to create all Python library symlinks
add_custom_target(python_python_symlinks ALL
  DEPENDS ${_cybld}/thrift/python/abstract_types.py ${_cybld}/thrift/python/metadata.py ${_cybld}/thrift/python/metadata.pyi ${_cybld}/thrift/python/test_helpers.py ${_cybld}/thrift/lib/python/any/typestub.py ${_cybld}/thrift/lib/python/any/any_registry.py ${_cybld}/thrift/lib/python/benchmark/benchmark_struct.py ${_cybld}/thrift/lib/python/benchmark/containers.py ${_cybld}/thrift/lib/python/benchmark/struct_memory.py ${_cybld}/thrift/python/client/client_wrapper.py ${_cybld}/thrift/python/client/__init__.py ${_cybld}/thrift/lib/python/conformance/any_registry.py ${_cybld}/thrift/lib/python/test/test_server.py ${_cybld}/thrift/lib/python/test/testing_utils.py ${_cybld}/thrift/lib/python/client/test/test_server.py ${_cybld}/thrift/lib/python/server/interceptor/test/interceptors.py ${_cybld}/thrift/python/test/adapters/datetime.py ${_cybld}/thrift/python/test/adapters/atoi.py ${_cybld}/thrift/python/test/adapters/noop.py
)

# Symlink .pxd and .h files from Cython libraries

add_custom_command(OUTPUT ${_cybld}/std_libcpp.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/std_libcpp.h
    ${_cybld}/std_libcpp.h
  COMMENT "Symlinking std_libcpp.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/std_libcpp.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/std_libcpp.pxd
    ${_cybld}/thrift/python/std_libcpp.pxd
  COMMENT "Symlinking thrift/python/std_libcpp.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/common.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/common.pxd
    ${_cybld}/thrift/python/common.pxd
  COMMENT "Symlinking thrift/python/common.pxd"
)

add_custom_command(OUTPUT ${_cybld}/Serializer.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/Serializer.h
    ${_cybld}/Serializer.h
  COMMENT "Symlinking Serializer.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/exceptions.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.pxd
    ${_cybld}/thrift/python/exceptions.pxd
  COMMENT "Symlinking thrift/python/exceptions.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/serializer.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/serializer.pxd
    ${_cybld}/thrift/python/serializer.pxd
  COMMENT "Symlinking thrift/python/serializer.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/types.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/types.pxd
    ${_cybld}/thrift/python/types.pxd
  COMMENT "Symlinking thrift/python/types.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/protocol.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/protocol.pxd
    ${_cybld}/thrift/python/protocol.pxd
  COMMENT "Symlinking thrift/python/protocol.pxd"
)

add_custom_command(OUTPUT ${_cybld}/Serializer.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/Serializer.h
    ${_cybld}/Serializer.h
  COMMENT "Symlinking Serializer.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/mutable_containers.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_containers.pxd
    ${_cybld}/thrift/python/mutable_containers.pxd
  COMMENT "Symlinking thrift/python/mutable_containers.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/mutable_exceptions.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_exceptions.pxd
    ${_cybld}/thrift/python/mutable_exceptions.pxd
  COMMENT "Symlinking thrift/python/mutable_exceptions.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/mutable_serializer.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_serializer.pxd
    ${_cybld}/thrift/python/mutable_serializer.pxd
  COMMENT "Symlinking thrift/python/mutable_serializer.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/mutable_typeinfos.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_typeinfos.pxd
    ${_cybld}/thrift/python/mutable_typeinfos.pxd
  COMMENT "Symlinking thrift/python/mutable_typeinfos.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/mutable_types.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_types.pxd
    ${_cybld}/thrift/python/mutable_types.pxd
  COMMENT "Symlinking thrift/python/mutable_types.pxd"
)

add_custom_command(OUTPUT ${_cybld}/any/serializer.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/any/serializer.h
    ${_cybld}/any/serializer.h
  COMMENT "Symlinking any/serializer.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/any/serializer.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/any/serializer.pxd
    ${_cybld}/thrift/python/any/serializer.pxd
  COMMENT "Symlinking thrift/python/any/serializer.pxd"
)

add_custom_command(OUTPUT ${_cybld}/capi/cpp_converter.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/capi/cpp_converter.h
    ${_cybld}/capi/cpp_converter.h
  COMMENT "Symlinking capi/cpp_converter.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/capi/cpp_converter.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/capi/cpp_converter.pxd
    ${_cybld}/thrift/python/capi/cpp_converter.pxd
  COMMENT "Symlinking thrift/python/capi/cpp_converter.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client/OmniClient.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/OmniClient.h
    ${_cybld}/client/OmniClient.h
  COMMENT "Symlinking client/OmniClient.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/omni_client.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/omni_client.pxd
    ${_cybld}/thrift/python/client/omni_client.pxd
  COMMENT "Symlinking thrift/python/client/omni_client.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client/RequestChannel.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/RequestChannel.h
    ${_cybld}/client/RequestChannel.h
  COMMENT "Symlinking client/RequestChannel.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/request_channel.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/request_channel.pxd
    ${_cybld}/thrift/python/client/request_channel.pxd
  COMMENT "Symlinking thrift/python/client/request_channel.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client/ssl.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/ssl.h
    ${_cybld}/client/ssl.h
  COMMENT "Symlinking client/ssl.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/ssl.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/ssl.pxd
    ${_cybld}/thrift/python/client/ssl.pxd
  COMMENT "Symlinking thrift/python/client/ssl.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/sync_client.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/sync_client.pxd
    ${_cybld}/thrift/python/client/sync_client.pxd
  COMMENT "Symlinking thrift/python/client/sync_client.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/sync_channel_factory.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/sync_channel_factory.pxd
    ${_cybld}/thrift/python/client/sync_channel_factory.pxd
  COMMENT "Symlinking thrift/python/client/sync_channel_factory.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/async_client.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/async_client.pxd
    ${_cybld}/thrift/python/client/async_client.pxd
  COMMENT "Symlinking thrift/python/client/async_client.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/client/async_client_factory.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/async_client_factory.pxd
    ${_cybld}/thrift/python/client/async_client_factory.pxd
  COMMENT "Symlinking thrift/python/client/async_client_factory.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/conformance/universal_name.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/conformance/universal_name.pxd
    ${_cybld}/thrift/python/conformance/universal_name.pxd
  COMMENT "Symlinking thrift/python/conformance/universal_name.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/async_processor.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/async_processor.pxd
    ${_cybld}/thrift/python/server_impl/async_processor.pxd
  COMMENT "Symlinking thrift/python/server_impl/async_processor.pxd"
)

add_custom_command(OUTPUT ${_cybld}/server/event_handler.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/event_handler.h
    ${_cybld}/server/event_handler.h
  COMMENT "Symlinking server/event_handler.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/event_handler.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/event_handler.pxd
    ${_cybld}/thrift/python/server_impl/event_handler.pxd
  COMMENT "Symlinking thrift/python/server_impl/event_handler.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/request_context.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/request_context.pxd
    ${_cybld}/thrift/python/server_impl/request_context.pxd
  COMMENT "Symlinking thrift/python/server_impl/request_context.pxd"
)

add_custom_command(OUTPUT ${_cybld}/server/PythonAsyncProcessor.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/PythonAsyncProcessor.h
    ${_cybld}/server/PythonAsyncProcessor.h
  COMMENT "Symlinking server/PythonAsyncProcessor.h"
)

add_custom_command(OUTPUT ${_cybld}/server/PythonAsyncProcessorFactory.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/PythonAsyncProcessorFactory.h
    ${_cybld}/server/PythonAsyncProcessorFactory.h
  COMMENT "Symlinking server/PythonAsyncProcessorFactory.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/python_async_processor.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/python_async_processor.pxd
    ${_cybld}/thrift/python/server_impl/python_async_processor.pxd
  COMMENT "Symlinking thrift/python/server_impl/python_async_processor.pxd"
)

add_custom_command(OUTPUT ${_cybld}/server/response_helpers.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/response_helpers.h
    ${_cybld}/server/response_helpers.h
  COMMENT "Symlinking server/response_helpers.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/streaming/py_promise.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/py_promise.pxd
    ${_cybld}/thrift/python/streaming/py_promise.pxd
  COMMENT "Symlinking thrift/python/streaming/py_promise.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/streaming/python_user_exception.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/python_user_exception.pxd
    ${_cybld}/thrift/python/streaming/python_user_exception.pxd
  COMMENT "Symlinking thrift/python/streaming/python_user_exception.pxd"
)

add_custom_command(OUTPUT ${_cybld}/streaming/Sink.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/Sink.h
    ${_cybld}/streaming/Sink.h
  COMMENT "Symlinking streaming/Sink.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/streaming/sink.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/sink.pxd
    ${_cybld}/thrift/python/streaming/sink.pxd
  COMMENT "Symlinking thrift/python/streaming/sink.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/streaming/stream.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/stream.pxd
    ${_cybld}/thrift/python/streaming/stream.pxd
  COMMENT "Symlinking thrift/python/streaming/stream.pxd"
)

add_custom_command(OUTPUT ${_cybld}/streaming/bidistream.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/bidistream.h
    ${_cybld}/streaming/bidistream.h
  COMMENT "Symlinking streaming/bidistream.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/streaming/bidistream.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/bidistream.pxd
    ${_cybld}/thrift/python/streaming/bidistream.pxd
  COMMENT "Symlinking thrift/python/streaming/bidistream.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test/typeinfo_test.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/typeinfo_test.pxd
    ${_cybld}/thrift/python/test/typeinfo_test.pxd
  COMMENT "Symlinking thrift/python/test/typeinfo_test.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client/test/event_handler_helper.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/event_handler_helper.h
    ${_cybld}/client/test/event_handler_helper.h
  COMMENT "Symlinking client/test/event_handler_helper.h"
)

add_custom_command(OUTPUT ${_cybld}/client/test/http2_helper.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/http2_helper.h
    ${_cybld}/client/test/http2_helper.h
  COMMENT "Symlinking client/test/http2_helper.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/client/test/http2_helper.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/http2_helper.pxd
    ${_cybld}/thrift/lib/python/client/test/http2_helper.pxd
  COMMENT "Symlinking thrift/lib/python/client/test/http2_helper.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client/test/client_event_handlers/handler.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/client_event_handlers/handler.h
    ${_cybld}/client/test/client_event_handlers/handler.h
  COMMENT "Symlinking client/test/client_event_handlers/handler.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/client/test/client_event_handler/handler.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/client_event_handlers/handler.pxd
    ${_cybld}/thrift/lib/python/client/test/client_event_handler/handler.pxd
  COMMENT "Symlinking thrift/lib/python/client/test/client_event_handler/handler.pxd"
)

add_custom_command(OUTPUT ${_cybld}/server/interceptor/PythonServerModule.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/PythonServerModule.h
    ${_cybld}/server/interceptor/PythonServerModule.h
  COMMENT "Symlinking server/interceptor/PythonServerModule.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/interceptor/server_module.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/server_module.pxd
    ${_cybld}/thrift/python/server_impl/interceptor/server_module.pxd
  COMMENT "Symlinking thrift/python/server_impl/interceptor/server_module.pxd"
)

add_custom_command(OUTPUT ${_cybld}/server/interceptor/PythonServiceInterceptor.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/PythonServiceInterceptor.h
    ${_cybld}/server/interceptor/PythonServiceInterceptor.h
  COMMENT "Symlinking server/interceptor/PythonServiceInterceptor.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/server_impl/interceptor/service_interceptor.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/service_interceptor.pxd
    ${_cybld}/thrift/python/server_impl/interceptor/service_interceptor.pxd
  COMMENT "Symlinking thrift/python/server_impl/interceptor/service_interceptor.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/python/test/python_async_processor_factory_test.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/test/python_async_processor_factory_test.pxd
    ${_cybld}/thrift/python/test/python_async_processor_factory_test.pxd
  COMMENT "Symlinking thrift/python/test/python_async_processor_factory_test.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/event_handlers/handler.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/event_handlers/handler.h
    ${_cybld}/test/event_handlers/handler.h
  COMMENT "Symlinking test/event_handlers/handler.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/test/event_handlers/handler.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/event_handlers/handler.pxd
    ${_cybld}/thrift/lib/python/test/event_handlers/handler.pxd
  COMMENT "Symlinking thrift/lib/python/test/event_handlers/handler.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/interactions/interaction_test.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/interaction_test.h
    ${_cybld}/test/interactions/interaction_test.h
  COMMENT "Symlinking test/interactions/interaction_test.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/test/interactions/run_interaction.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/run_interaction.pxd
    ${_cybld}/thrift/lib/python/test/interactions/run_interaction.pxd
  COMMENT "Symlinking thrift/lib/python/test/interactions/run_interaction.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/metadata_response/metadata_response.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/metadata_response/metadata_response.h
    ${_cybld}/test/metadata_response/metadata_response.h
  COMMENT "Symlinking test/metadata_response/metadata_response.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/python/test/metadata_response/metadata_response.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/metadata_response/metadata_response.pxd
    ${_cybld}/thrift/lib/python/test/metadata_response/metadata_response.pxd
  COMMENT "Symlinking thrift/lib/python/test/metadata_response/metadata_response.pxd"
)

# Target to create all .pxd and .h header symlinks
add_custom_target(python_pxd_symlinks ALL
  DEPENDS ${_cybld}/thrift/python/std_libcpp.pxd ${_cybld}/thrift/python/common.pxd ${_cybld}/thrift/python/exceptions.pxd ${_cybld}/thrift/python/serializer.pxd ${_cybld}/thrift/python/types.pxd ${_cybld}/thrift/python/protocol.pxd ${_cybld}/thrift/python/mutable_containers.pxd ${_cybld}/thrift/python/mutable_exceptions.pxd ${_cybld}/thrift/python/mutable_serializer.pxd ${_cybld}/thrift/python/mutable_typeinfos.pxd ${_cybld}/thrift/python/mutable_types.pxd ${_cybld}/thrift/python/any/serializer.pxd ${_cybld}/thrift/python/capi/cpp_converter.pxd ${_cybld}/thrift/python/client/omni_client.pxd ${_cybld}/thrift/python/client/request_channel.pxd ${_cybld}/thrift/python/client/ssl.pxd ${_cybld}/thrift/python/client/sync_client.pxd ${_cybld}/thrift/python/client/sync_channel_factory.pxd ${_cybld}/thrift/python/client/async_client.pxd ${_cybld}/thrift/python/client/async_client_factory.pxd ${_cybld}/thrift/python/conformance/universal_name.pxd ${_cybld}/thrift/python/server_impl/async_processor.pxd ${_cybld}/thrift/python/server_impl/event_handler.pxd ${_cybld}/thrift/python/server_impl/request_context.pxd ${_cybld}/thrift/python/server_impl/python_async_processor.pxd ${_cybld}/thrift/python/streaming/py_promise.pxd ${_cybld}/thrift/python/streaming/python_user_exception.pxd ${_cybld}/thrift/python/streaming/sink.pxd ${_cybld}/thrift/python/streaming/stream.pxd ${_cybld}/thrift/python/streaming/bidistream.pxd ${_cybld}/thrift/python/test/typeinfo_test.pxd ${_cybld}/thrift/lib/python/client/test/http2_helper.pxd ${_cybld}/thrift/lib/python/client/test/client_event_handler/handler.pxd ${_cybld}/thrift/python/server_impl/interceptor/server_module.pxd ${_cybld}/thrift/python/server_impl/interceptor/service_interceptor.pxd ${_cybld}/thrift/python/test/python_async_processor_factory_test.pxd ${_cybld}/thrift/lib/python/test/event_handlers/handler.pxd ${_cybld}/thrift/lib/python/test/interactions/run_interaction.pxd ${_cybld}/thrift/lib/python/test/metadata_response/metadata_response.pxd ${_cybld}/std_libcpp.h ${_cybld}/Serializer.h ${_cybld}/Serializer.h ${_cybld}/any/serializer.h ${_cybld}/capi/cpp_converter.h ${_cybld}/client/OmniClient.h ${_cybld}/client/RequestChannel.h ${_cybld}/client/ssl.h ${_cybld}/server/event_handler.h ${_cybld}/server/PythonAsyncProcessor.h ${_cybld}/server/PythonAsyncProcessorFactory.h ${_cybld}/server/response_helpers.h ${_cybld}/streaming/Sink.h ${_cybld}/streaming/bidistream.h ${_cybld}/client/test/event_handler_helper.h ${_cybld}/client/test/http2_helper.h ${_cybld}/client/test/client_event_handlers/handler.h ${_cybld}/server/interceptor/PythonServerModule.h ${_cybld}/server/interceptor/PythonServiceInterceptor.h ${_cybld}/test/event_handlers/handler.h ${_cybld}/test/interactions/interaction_test.h ${_cybld}/test/metadata_response/metadata_response.h
)

# Symlink .pyx and C++ source files for Cython compilation

add_custom_command(OUTPUT ${_cybld}/std_libcpp.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/std_libcpp.cpp
    ${_cybld}/std_libcpp.cpp
  COMMENT "Symlinking std_libcpp.cpp"
)

add_custom_command(OUTPUT ${_cybld}/common.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/common.pyx
    ${_cybld}/common.pyx
  COMMENT "Symlinking common.pyx"
)

add_custom_command(OUTPUT ${_cybld}/Serializer.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/Serializer.cpp
    ${_cybld}/Serializer.cpp
  COMMENT "Symlinking Serializer.cpp"
)

add_custom_command(OUTPUT ${_cybld}/adapter.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter.pyx
    ${_cybld}/adapter.pyx
  COMMENT "Symlinking adapter.pyx"
)

add_custom_command(OUTPUT ${_cybld}/exceptions.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.pyx
    ${_cybld}/exceptions.pyx
  COMMENT "Symlinking exceptions.pyx"
)

add_custom_command(OUTPUT ${_cybld}/serializer.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/serializer.pyx
    ${_cybld}/serializer.pyx
  COMMENT "Symlinking serializer.pyx"
)

add_custom_command(OUTPUT ${_cybld}/types.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/types.pyx
    ${_cybld}/types.pyx
  COMMENT "Symlinking types.pyx"
)

add_custom_command(OUTPUT ${_cybld}/protocol.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/protocol.pyx
    ${_cybld}/protocol.pyx
  COMMENT "Symlinking protocol.pyx"
)

add_custom_command(OUTPUT ${_cybld}/converter.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/converter.pyx
    ${_cybld}/converter.pyx
  COMMENT "Symlinking converter.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_containers.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_containers.pyx
    ${_cybld}/mutable_containers.pyx
  COMMENT "Symlinking mutable_containers.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_exceptions.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_exceptions.pyx
    ${_cybld}/mutable_exceptions.pyx
  COMMENT "Symlinking mutable_exceptions.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_serializer.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_serializer.pyx
    ${_cybld}/mutable_serializer.pyx
  COMMENT "Symlinking mutable_serializer.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_typeinfos.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_typeinfos.pyx
    ${_cybld}/mutable_typeinfos.pyx
  COMMENT "Symlinking mutable_typeinfos.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_types.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_types.pyx
    ${_cybld}/mutable_types.pyx
  COMMENT "Symlinking mutable_types.pyx"
)

add_custom_command(OUTPUT ${_cybld}/mutable_converter.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/mutable_converter.pyx
    ${_cybld}/mutable_converter.pyx
  COMMENT "Symlinking mutable_converter.pyx"
)

add_custom_command(OUTPUT ${_cybld}/any/serializer.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/any/serializer.pyx
    ${_cybld}/any/serializer.pyx
  COMMENT "Symlinking any/serializer.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/OmniClient.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/OmniClient.cpp
    ${_cybld}/client/OmniClient.cpp
  COMMENT "Symlinking client/OmniClient.cpp"
)

add_custom_command(OUTPUT ${_cybld}/client/omni_client.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/omni_client.pyx
    ${_cybld}/client/omni_client.pyx
  COMMENT "Symlinking client/omni_client.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/RequestChannel.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/RequestChannel.cpp
    ${_cybld}/client/RequestChannel.cpp
  COMMENT "Symlinking client/RequestChannel.cpp"
)

add_custom_command(OUTPUT ${_cybld}/client/request_channel.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/request_channel.pyx
    ${_cybld}/client/request_channel.pyx
  COMMENT "Symlinking client/request_channel.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/ssl.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/ssl.cpp
    ${_cybld}/client/ssl.cpp
  COMMENT "Symlinking client/ssl.cpp"
)

add_custom_command(OUTPUT ${_cybld}/client/ssl.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/ssl.pyx
    ${_cybld}/client/ssl.pyx
  COMMENT "Symlinking client/ssl.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/sync_client.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/sync_client.pyx
    ${_cybld}/client/sync_client.pyx
  COMMENT "Symlinking client/sync_client.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/sync_channel_factory.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/sync_channel_factory.pyx
    ${_cybld}/client/sync_channel_factory.pyx
  COMMENT "Symlinking client/sync_channel_factory.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/sync_client_factory.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/sync_client_factory.pyx
    ${_cybld}/client/sync_client_factory.pyx
  COMMENT "Symlinking client/sync_client_factory.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/async_client.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/async_client.pyx
    ${_cybld}/client/async_client.pyx
  COMMENT "Symlinking client/async_client.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/async_client_factory.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/async_client_factory.pyx
    ${_cybld}/client/async_client_factory.pyx
  COMMENT "Symlinking client/async_client_factory.pyx"
)

add_custom_command(OUTPUT ${_cybld}/conformance/universal_name.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/conformance/universal_name.pyx
    ${_cybld}/conformance/universal_name.pyx
  COMMENT "Symlinking conformance/universal_name.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/async_processor.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/async_processor.pyx
    ${_cybld}/server/async_processor.pyx
  COMMENT "Symlinking server/async_processor.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/event_handler.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/event_handler.cpp
    ${_cybld}/server/event_handler.cpp
  COMMENT "Symlinking server/event_handler.cpp"
)

add_custom_command(OUTPUT ${_cybld}/server/request_context.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/request_context.pyx
    ${_cybld}/server/request_context.pyx
  COMMENT "Symlinking server/request_context.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/PythonAsyncProcessor.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/PythonAsyncProcessor.cpp
    ${_cybld}/server/PythonAsyncProcessor.cpp
  COMMENT "Symlinking server/PythonAsyncProcessor.cpp"
)

add_custom_command(OUTPUT ${_cybld}/server/PythonAsyncProcessorFactory.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/PythonAsyncProcessorFactory.cpp
    ${_cybld}/server/PythonAsyncProcessorFactory.cpp
  COMMENT "Symlinking server/PythonAsyncProcessorFactory.cpp"
)

add_custom_command(OUTPUT ${_cybld}/server/python_async_processor.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/python_async_processor.pyx
    ${_cybld}/server/python_async_processor.pyx
  COMMENT "Symlinking server/python_async_processor.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/server.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/server.pyx
    ${_cybld}/server/server.pyx
  COMMENT "Symlinking server/server.pyx"
)

add_custom_command(OUTPUT ${_cybld}/streaming/py_promise.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/py_promise.pyx
    ${_cybld}/streaming/py_promise.pyx
  COMMENT "Symlinking streaming/py_promise.pyx"
)

add_custom_command(OUTPUT ${_cybld}/streaming/python_user_exception.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/python_user_exception.pyx
    ${_cybld}/streaming/python_user_exception.pyx
  COMMENT "Symlinking streaming/python_user_exception.pyx"
)

add_custom_command(OUTPUT ${_cybld}/streaming/Sink.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/Sink.cpp
    ${_cybld}/streaming/Sink.cpp
  COMMENT "Symlinking streaming/Sink.cpp"
)

add_custom_command(OUTPUT ${_cybld}/streaming/sink.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/sink.pyx
    ${_cybld}/streaming/sink.pyx
  COMMENT "Symlinking streaming/sink.pyx"
)

add_custom_command(OUTPUT ${_cybld}/streaming/stream.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/stream.pyx
    ${_cybld}/streaming/stream.pyx
  COMMENT "Symlinking streaming/stream.pyx"
)

add_custom_command(OUTPUT ${_cybld}/streaming/bidistream.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/bidistream.cpp
    ${_cybld}/streaming/bidistream.cpp
  COMMENT "Symlinking streaming/bidistream.cpp"
)

add_custom_command(OUTPUT ${_cybld}/streaming/bidistream.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/streaming/bidistream.pyx
    ${_cybld}/streaming/bidistream.pyx
  COMMENT "Symlinking streaming/bidistream.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/typeinfo_test.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/typeinfo_test.pyx
    ${_cybld}/test/typeinfo_test.pyx
  COMMENT "Symlinking test/typeinfo_test.pyx"
)

add_custom_command(OUTPUT ${_cybld}/capi/test/marshal_fixture.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/capi/test/marshal_fixture.pyx
    ${_cybld}/capi/test/marshal_fixture.pyx
  COMMENT "Symlinking capi/test/marshal_fixture.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/test/exceptions_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/exceptions_helper.pyx
    ${_cybld}/client/test/exceptions_helper.pyx
  COMMENT "Symlinking client/test/exceptions_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/test/event_handler_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/event_handler_helper.pyx
    ${_cybld}/client/test/event_handler_helper.pyx
  COMMENT "Symlinking client/test/event_handler_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/test/http2_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/http2_helper.pyx
    ${_cybld}/client/test/http2_helper.pyx
  COMMENT "Symlinking client/test/http2_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client/test/client_event_handlers/helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client/test/client_event_handlers/helper.pyx
    ${_cybld}/client/test/client_event_handlers/helper.pyx
  COMMENT "Symlinking client/test/client_event_handlers/helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/interceptor/server_module.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/server_module.pyx
    ${_cybld}/server/interceptor/server_module.pyx
  COMMENT "Symlinking server/interceptor/server_module.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/interceptor/PythonServiceInterceptor.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/PythonServiceInterceptor.cpp
    ${_cybld}/server/interceptor/PythonServiceInterceptor.cpp
  COMMENT "Symlinking server/interceptor/PythonServiceInterceptor.cpp"
)

add_custom_command(OUTPUT ${_cybld}/server/interceptor/service_interceptor.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/service_interceptor.pyx
    ${_cybld}/server/interceptor/service_interceptor.pyx
  COMMENT "Symlinking server/interceptor/service_interceptor.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server/test/python_async_processor_factory_test.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server/test/python_async_processor_factory_test.pyx
    ${_cybld}/server/test/python_async_processor_factory_test.pyx
  COMMENT "Symlinking server/test/python_async_processor_factory_test.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/cpp_conversion/cpp_converter_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/cpp_conversion/cpp_converter_helper.pyx
    ${_cybld}/test/cpp_conversion/cpp_converter_helper.pyx
  COMMENT "Symlinking test/cpp_conversion/cpp_converter_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/event_handlers/helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/event_handlers/helper.pyx
    ${_cybld}/test/event_handlers/helper.pyx
  COMMENT "Symlinking test/event_handlers/helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/interactions/run_interaction.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/run_interaction.pyx
    ${_cybld}/test/interactions/run_interaction.pyx
  COMMENT "Symlinking test/interactions/run_interaction.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/metadata_response/metadata_response.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/metadata_response/metadata_response.pyx
    ${_cybld}/test/metadata_response/metadata_response.pyx
  COMMENT "Symlinking test/metadata_response/metadata_response.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/request_context_extractor/request_context_extractor.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/request_context_extractor/request_context_extractor.pyx
    ${_cybld}/test/request_context_extractor/request_context_extractor.pyx
  COMMENT "Symlinking test/request_context_extractor/request_context_extractor.pyx"
)

# Target to create all Cython source symlinks
add_custom_target(python_cython_source_symlinks ALL
  DEPENDS ${_cybld}/std_libcpp.cpp ${_cybld}/common.pyx ${_cybld}/Serializer.cpp ${_cybld}/adapter.pyx ${_cybld}/exceptions.pyx ${_cybld}/serializer.pyx ${_cybld}/types.pyx ${_cybld}/protocol.pyx ${_cybld}/converter.pyx ${_cybld}/mutable_containers.pyx ${_cybld}/mutable_exceptions.pyx ${_cybld}/mutable_serializer.pyx ${_cybld}/mutable_typeinfos.pyx ${_cybld}/mutable_types.pyx ${_cybld}/mutable_converter.pyx ${_cybld}/any/serializer.pyx ${_cybld}/client/OmniClient.cpp ${_cybld}/client/omni_client.pyx ${_cybld}/client/RequestChannel.cpp ${_cybld}/client/request_channel.pyx ${_cybld}/client/ssl.cpp ${_cybld}/client/ssl.pyx ${_cybld}/client/sync_client.pyx ${_cybld}/client/sync_channel_factory.pyx ${_cybld}/client/sync_client_factory.pyx ${_cybld}/client/async_client.pyx ${_cybld}/client/async_client_factory.pyx ${_cybld}/conformance/universal_name.pyx ${_cybld}/server/async_processor.pyx ${_cybld}/server/event_handler.cpp ${_cybld}/server/request_context.pyx ${_cybld}/server/PythonAsyncProcessor.cpp ${_cybld}/server/PythonAsyncProcessorFactory.cpp ${_cybld}/server/python_async_processor.pyx ${_cybld}/server/server.pyx ${_cybld}/streaming/py_promise.pyx ${_cybld}/streaming/python_user_exception.pyx ${_cybld}/streaming/Sink.cpp ${_cybld}/streaming/sink.pyx ${_cybld}/streaming/stream.pyx ${_cybld}/streaming/bidistream.cpp ${_cybld}/streaming/bidistream.pyx ${_cybld}/test/typeinfo_test.pyx ${_cybld}/capi/test/marshal_fixture.pyx ${_cybld}/client/test/exceptions_helper.pyx ${_cybld}/client/test/event_handler_helper.pyx ${_cybld}/client/test/http2_helper.pyx ${_cybld}/client/test/client_event_handlers/helper.pyx ${_cybld}/server/interceptor/server_module.pyx ${_cybld}/server/interceptor/PythonServiceInterceptor.cpp ${_cybld}/server/interceptor/service_interceptor.pyx ${_cybld}/server/test/python_async_processor_factory_test.pyx ${_cybld}/test/cpp_conversion/cpp_converter_helper.pyx ${_cybld}/test/event_handlers/helper.pyx ${_cybld}/test/interactions/run_interaction.pyx ${_cybld}/test/metadata_response/metadata_response.pyx ${_cybld}/test/request_context_extractor/request_context_extractor.pyx
)

# Target for Cython API generation (--api-only phase)
add_custom_target(python_cython_api_generation ALL
  DEPENDS python_python_symlinks python_pxd_symlinks python_cython_source_symlinks
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py --api-only
  WORKING_DIRECTORY ${_cybld}
  COMMENT "Generating Cython API headers"
)

# Target for Cython compilation (build_ext phase)
add_custom_target(python_cython_build_ext ALL
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py build_ext --inplace
  WORKING_DIRECTORY ${_cybld}
  DEPENDS python_cython_api_generation
  COMMENT "Building Cython extensions"
)

# Buck parameters for all targets:

# std_libcpp:
#   package: thrift.python

# common:
#   package: thrift.python

# types:
#   package: thrift.python
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
#   api: ['python_async_processor']
#   cpp_compiler_flags: ['-D__PYX_ENUM_CLASS_DECL=']

# server:
#   package: thrift.python

# py_promise:
#   package: thrift.python.streaming
#   api: ['py_promise']

# python_user_exception:
#   package: thrift.python.streaming

# sink:
#   package: thrift.python.streaming
#   api: ['sink']

# stream:
#   package: thrift.python.streaming

# bidistream:
#   package: thrift.python.streaming
#   api: ['bidistream']

# typeinfo_ctest:
#   package: thrift.python.test

# marshal_fixture:
#   package: thrift.python.marshal

# exceptions_helper:
#   package: thrift.lib.python.client.test

# event_handler_helper:
#   package: thrift.lib.python.client.test

# http2_helper:
#   package: thrift.lib.python.client.test

# client:
#   package: thrift.lib.python.client.test.client_event_handler

# server_module:
#   package: thrift.python.server_impl.interceptor

# service_interceptor:
#   package: thrift.python.server_impl.interceptor
#   api: ['service_interceptor']

# python_async_processor_factory_ctest:
#   package: thrift.python.test

# cpp_converter_helper:
#   package: thrift.python.test

# handler:
#   package: thrift.lib.python.test.event_handlers

# run_interaction:
#   package: thrift.lib.python.test.interactions

# metadata_response:
#   package: thrift.lib.python.test.metadata_response

# request_context_extractor:
#   package: thrift.python.test.request_context_extractor

# abstract_types:
#   package: thrift.python

# metadata:
#   package: thrift.python

# test_helpers:
#   package: thrift.python

# typestub:
#   package: thrift.lib.python.any

# any_registry:
#   package: thrift.lib.python.any

# struct_benchmark_lib:
#   package: thrift.lib.python.benchmark

# containers_benchmark_lib:
#   package: thrift.lib.python.benchmark

# struct_memory_lib:
#   package: thrift.lib.python.benchmark

# client_wrapper:
#   package: thrift.python.client

# base:
#   package: thrift.python.client

# any_registry:
#   package: thrift.lib.python.conformance

# test_server:
#   package: thrift.lib.python.test

# testing_utils:
#   package: thrift.lib.python.test

# test_server:
#   package: thrift.lib.python.client.test

# interceptors:
#   package: thrift.lib.python.server.interceptor.test

# datetime:
#   package: thrift.python.test.adapters

# atoi:
#   package: thrift.python.test.adapters

# noop:
#   package: thrift.python.test.adapters