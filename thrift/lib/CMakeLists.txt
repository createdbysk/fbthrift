# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(FindFolly)
include(FindPackageHandleStandardArgs)
find_package(Boost MODULE REQUIRED)

set(LIB_HOME ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(thrift)
add_subdirectory(cpp)
add_subdirectory(cpp2)
if(thriftpy)
  add_subdirectory(py)
endif()

if(thriftpy3)
  set(_cybld "${CMAKE_CURRENT_BINARY_DIR}/cybld")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/client/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/server/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/server/flagged/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/server/interceptor/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/any/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/conformance/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/streaming/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/py3/")

  # So that cython includes work correctly
  file(TOUCH "${_cybld}/thrift/__init__.pxd")
  file(TOUCH "${_cybld}/thrift/python/__init__.pxd")
  file(TOUCH "${_cybld}/thrift/py3/__init__.pxd")

  ###
  # First, run Thrift compiler on metadata.thrift. thrift-python runtime depends on
  # apache.thrift.metadata package, which is created and installed later in setup.py.
  ###
  add_custom_target(
    generate_apache_thrift_metadata_python
    COMMAND
      thrift1 -I ${CMAKE_SOURCE_DIR} --out . --gen "mstch_python:include_prefix=thrift"
      ${CMAKE_CURRENT_SOURCE_DIR}/thrift/metadata.thrift
    WORKING_DIRECTORY ${_cybld}
    BYPRODUCTS
      ${_cybld}/apache/thrift/metadata/thrift_abstract_types.py
      ${_cybld}/apache/thrift/metadata/thrift_clients.py
      ${_cybld}/apache/thrift/metadata/thrift_enums.py
      ${_cybld}/apache/thrift/metadata/thrift_metadata.py
      ${_cybld}/apache/thrift/metadata/thrift_mutable_clients.py
      ${_cybld}/apache/thrift/metadata/thrift_mutable_services.py
      ${_cybld}/apache/thrift/metadata/thrift_mutable_types.py
      ${_cybld}/apache/thrift/metadata/thrift_mutable_types.pyi
      ${_cybld}/apache/thrift/metadata/thrift_services.py
      ${_cybld}/apache/thrift/metadata/thrift_types.py
      ${_cybld}/apache/thrift/metadata/thrift_types.pyi
  )

  ###
  # Also generate py3 version for apache.thrift.metadata (required by py3/metadata.pyx)
  ###
  add_custom_target(
    generate_apache_thrift_metadata_py3
    COMMAND
      thrift1 -I ${CMAKE_SOURCE_DIR} --out . --gen "mstch_py3:include_prefix=thrift"
      ${CMAKE_CURRENT_SOURCE_DIR}/thrift/metadata.thrift
    WORKING_DIRECTORY ${_cybld}
    BYPRODUCTS
      ${_cybld}/apache/thrift/metadata/cbindings.pxd
      ${_cybld}/apache/thrift/metadata/cbindings.pyx
      ${_cybld}/apache/thrift/metadata/metadata.pxd
      ${_cybld}/apache/thrift/metadata/metadata.pyx
  )

  ####
  # Next, prepare for building cython extensions by creating the necessary symlinks in the cybld directory
  ####
  add_custom_target(create_binding_symlink_python_types ALL)
  foreach(
    _filerelpath
      "python/types.pxd"
      "python/types.pyx"
      "py3/stream.pxd"
      "py3/stream.pyx"
  )
    set(_src "${CMAKE_CURRENT_SOURCE_DIR}/${_filerelpath}")
    get_filename_component(_src_dir "${_src}" DIRECTORY)
    file(RELATIVE_PATH _filereldir ${CMAKE_CURRENT_SOURCE_DIR} ${_src_dir})
    get_filename_component(_target_file "${_src}" NAME)


    message(
      STATUS
      "Linking ${_src} to ${_cybld}/thrift/${_filereldir}/_${_target_file}"
    )

    add_custom_command(
      TARGET
      create_binding_symlink_python_types
      PRE_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_cybld}/thrift/${_filereldir}/_${_target_file}"
    )
  endforeach()
  # Below symlinks simplify cythonize logic in setup.py
  add_custom_command(
    TARGET
    create_binding_symlink_python_types
    PRE_BUILD
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/server/server.pxd" "${_cybld}/thrift/python/server.pxd"
  )
  add_custom_command(
    TARGET
    create_binding_symlink_python_types
    PRE_BUILD
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/server/server.pyx" "${_cybld}/thrift/python/server.pyx"
  )

  # Helper function to create a symlink with a different name than source
  function(create_renamed_binding_symlink src_file dest_name)
    message(STATUS "Linking ${CMAKE_CURRENT_SOURCE_DIR}/${src_file} to ${_cybld}/thrift/${src_file} as ${dest_name}")
    get_filename_component(_dest_dir "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}" DIRECTORY)
    file(RELATIVE_PATH _dest_reldir ${CMAKE_CURRENT_SOURCE_DIR} ${_dest_dir})
    add_custom_command(
      TARGET create_binding_symlink_python
      PRE_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}"
        "${_cybld}/thrift/${_dest_reldir}/${dest_name}"
    )
  endfunction()

  add_custom_target(create_binding_symlink_python ALL)
  file(GLOB BindingFiles
    "python/abstract_types.py"
    "python/client/client_wrapper.py"
    "python/client/__init__.py"
    "python/metadata.py"
    "python/client/async_client_factory.pxd"
    "python/client/async_client.pxd"
    "python/client/omni_client.pxd"
    "python/client/request_channel.pxd"
    "python/client/ssl.pxd"
    "python/client/sync_channel_factory.pxd"
    "python/client/sync_client.pxd"
    "python/common.pxd"
    "python/exceptions.pxd"
    "python/mutable_containers.pxd"
    "python/mutable_exceptions.pxd"
    "python/mutable_serializer.pxd"
    "python/mutable_typeinfos.pxd"
    "python/mutable_types.pxd"
    "python/protocol.pxd"
    "python/serializer.pxd"
    "python/any/serializer.pxd"
    "python/conformance/universal_name.pxd"
    "python/server/async_processor.pxd"
    "python/server/event_handler.pxd"
    "python/server/interceptor/server_module.pxd"
    "python/server/interceptor/service_interceptor.pxd"
    "python/server/python_async_processor.pxd"
    "python/server/request_context.pxd"
    "python/server/server.pxd"
    "python/std_libcpp.pxd"
    "python/streaming/stream.pxd"
    "python/streaming/py_promise.pxd"
    "python/streaming/python_user_exception.pxd"
    "python/streaming/sink.pxd"
    "python/streaming/bidistream.pxd"
    "python/types.pxd"
    "python/adapter.pyx"
    "python/client/async_client_factory.pyx"
    "python/client/async_client.pyx"
    "python/client/omni_client.pyx"
    "python/client/request_channel.pyx"
    "python/client/ssl.pyx"
    "python/client/sync_channel_factory.pyx"
    "python/client/sync_client_factory.pyx"
    "python/client/sync_client.pyx"
    "python/common.pyx"
    "python/converter.pyx"
    "python/exceptions.pyx"
    "python/mutable_containers.pyx"
    "python/mutable_converter.pyx"
    "python/mutable_exceptions.pyx"
    "python/mutable_serializer.pyx"
    "python/mutable_typeinfos.pyx"
    "python/mutable_types.pyx"
    "python/protocol.pyx"
    "python/serializer.pyx"
    "python/streaming/stream.pyx"
    "python/streaming/py_promise.pyx"
    "python/streaming/python_user_exception.pyx"
    "python/streaming/PythonUserException.cpp"
    "python/streaming/PythonUserException.h"
    "python/streaming/sink.pyx"
    "python/streaming/Sink.cpp"
    "python/streaming/Sink.h"
    "python/streaming/bidistream.pyx"
    "python/streaming/bidistream.h"
    "python/streaming/StreamElementEncoder.cpp"
    "python/streaming/StreamElementEncoder.h"
    "python/streaming/SinkElementDecoder.h"
    "python/any/serializer.pyx"
    "python/conformance/universal_name.pyx"
    "python/server/async_processor.pyx"
    "python/server/interceptor/server_module.pyx"
    "python/server/interceptor/service_interceptor.pyx"
    "python/server/python_async_processor.pyx"
    "python/server/request_context.pyx"
    "python/server/server.pyx"
    "python/types.h"
    "python/Serializer.h"
    "python/server/PythonAsyncProcessor.cpp"
    "python/server/PythonAsyncProcessorFactory.cpp"
    "python/std_libcpp.cpp"
    "python/std_libcpp.h"
    "python/server/event_handler.cpp"
    "python/server/event_handler.h"
    "python/server/interceptor/PythonServiceInterceptor.cpp"
    "python/server/interceptor/PythonServiceInterceptor.h"
  )

  foreach(_src ${BindingFiles})
    file(RELATIVE_PATH _filerelpath ${CMAKE_CURRENT_SOURCE_DIR} ${_src})
    get_filename_component(_target_file "${_src}" NAME)

    message(
      STATUS
      "Linking ${_src} to ${_cybld}/thrift/${_filerelpath}"
    )

    add_custom_command(
      TARGET
      create_binding_symlink_python
      PRE_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_cybld}/thrift/${_filerelpath}"
    )
  endforeach()

  # Special case: bidistream.cpp needs to be symlinked with capital B to avoid
  # Cython conflict (bidistream.pyx would generate bidistream.cpp, conflicting
  # with handwritten bidistream.cpp). Sink.cpp and PythonUserException.cpp work
  # fine because their capital letters differ from lowercase .pyx names.
  create_renamed_binding_symlink("python/streaming/bidistream.cpp" "Bidistream.cpp")

  add_custom_target(create_binding_symlink_py3 ALL)
  file(GLOB BindingFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/py3/*.pxd"
    "${CMAKE_CURRENT_SOURCE_DIR}/py3/*.pyx"
  )

  foreach(_src ${BindingFiles})
    get_filename_component(_target_file "${_src}" NAME)

    message(
      STATUS
      "Linking ${_src} to ${_cybld}/thrift/py3/${_target_file}"
    )

    add_custom_command(
      TARGET
      create_binding_symlink_py3
      PRE_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_cybld}/thrift/py3/${_target_file}"
    )
  endforeach()

  #####
  # Compile a few *_api.h headers first.
  #####
  # List all headers generated by setup.py --api-only
  set(CYTHON_GENERATED_API_HEADERS
    ${_cybld}/thrift/python/_types_api.h
    ${_cybld}/thrift/python/server/python_async_processor_api.h
    ${_cybld}/thrift/python/server/request_context_api.h
    ${_cybld}/thrift/python/server/interceptor/service_interceptor_api.h
    ${_cybld}/thrift/python/server_impl/python_async_processor_api.h
    ${_cybld}/thrift/python/server_impl/request_context_api.h
    ${_cybld}/thrift/python/server_impl/interceptor/service_interceptor_api.h
    ${_cybld}/thrift/py3/_stream_api.h
    ${_cybld}/thrift/python/streaming/sink_api.h
    ${_cybld}/thrift/python/streaming/bidistream_api.h
    ${_cybld}/thrift/python/streaming/py_promise_api.h
  )

  add_custom_command(
    OUTPUT ${CYTHON_GENERATED_API_HEADERS}
    COMMAND ${CMAKE_COMMAND} -E env
      "CFLAGS=${CMAKE_C_FLAGS}"
      "CXXFLAGS=${CMAKE_CXX_FLAGS}"
      "CXX=${CMAKE_CXX_COMPILER}"
      "CYTHON_INCLUDE_PATH=${cython_include_path}"
      python3 ${CMAKE_CURRENT_SOURCE_DIR}/setup.py -v --api-only
    DEPENDS
      create_binding_symlink_python_types
      create_binding_symlink_python
      create_binding_symlink_py3
      create_binding_symlink_server_impl
      thriftcpp2
    WORKING_DIRECTORY ${_cybld}
    COMMENT "Generating Cython API headers"
  )

  add_custom_target(
    thrift_python_types_bindings ALL
    DEPENDS ${CYTHON_GENERATED_API_HEADERS}
  )

  # After cython runs, link _types_api.h to types_api.h
  add_custom_target(
    create_cython_types_api_symlink ALL
    DEPENDS ${_cybld}/thrift/python/_types_api.h
    WORKING_DIRECTORY ${_cybld})
  file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/")
  file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/server")
  file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/server/interceptor")
  file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/streaming")
  file(MAKE_DIRECTORY "${_cybld}/thrift/lib/py3/")

  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/_types_api.h" "${_cybld}/thrift/lib/python/types_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/_types.h" "${_cybld}/thrift/lib/python/_types.h"
  )
  # Changed from server/ to server_impl/ because:
  # - C++ code expects import_thrift__python__server_impl__python_async_processor
  # - Buck uses package = "thrift.python.server_impl" which makes Cython generate server_impl API functions
  # - Must match the import function names in the generated API headers
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/server_impl/python_async_processor_api.h" "${_cybld}/thrift/lib/python/server/python_async_processor_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/server_impl/request_context_api.h" "${_cybld}/thrift/lib/python/server/request_context_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/python/server_impl/interceptor/service_interceptor_api.h" "${_cybld}/thrift/lib/python/server/interceptor/service_interceptor_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/py3/_stream_api.h" "${_cybld}/thrift/lib/py3/stream_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/thrift/py3/_stream.h" "${_cybld}/thrift/lib/py3/_stream.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/generated/thrift/python/streaming/sink_api.h" "${_cybld}/thrift/lib/python/streaming/sink_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/generated/thrift/python/streaming/bidistream_api.h" "${_cybld}/thrift/lib/python/streaming/bidistream_api.h"
  )
  add_custom_command(
    TARGET
    create_cython_types_api_symlink
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink "${_cybld}/generated/thrift/python/streaming/py_promise_api.h" "${_cybld}/thrift/lib/python/streaming/py_promise_api.h"
  )
  add_library(
    thrift_python_cpp
      python/client/OmniClient.cpp
      python/client/RequestChannel.cpp
      python/client/ssl.cpp
      python/streaming/StreamElementEncoder.cpp
      python/streaming/PythonUserException.cpp
      python/types.cpp
      python/Serializer.cpp
      py3/stream.cpp
  )
  add_dependencies(thrift_python_cpp thrift_python_types_bindings create_cython_types_api_symlink)
  set_property(TARGET thrift_python_cpp PROPERTY VERSION ${PACKAGE_VERSION})
  target_compile_definitions(thrift_python_cpp PRIVATE BOOST_NO_AUTO_PTR)
  target_compile_definitions(thrift_python_cpp PRIVATE THRIFT_NO_HTTP_CLIENT_CHANNEL)
  target_include_directories(thrift_python_cpp PRIVATE "${_cybld}" ${PYTHON_INCLUDE_DIRS})
  target_link_libraries(
    thrift_python_cpp
    PUBLIC
      thriftcpp2
      Folly::folly
      Folly::folly_python_cpp
    )
  install(
    TARGETS thrift_python_cpp
    EXPORT thrift
  )
  install(
    TARGETS thrift_python_cpp
    DESTINATION ${py_install_dir}
  )

  #####
  # Create server_impl alias for OSS builds
  # Buck internal builds use package = "thrift.python.server_impl" remapping.
  # OSS CMake builds need this alias created manually.
  #####
  add_custom_target(create_binding_symlink_server_impl ALL)

  # Create server_impl directory structure
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/server_impl")
  file(MAKE_DIRECTORY "${_cybld}/thrift/python/server_impl/interceptor")

  # Create symlinks for server_impl/*.pxd -> server/*.pxd (compile-time cimport)
  file(GLOB ServerImplFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/python/server/*.pxd"
    "${CMAKE_CURRENT_SOURCE_DIR}/python/server/*.pyx"
  )

  foreach(_src ${ServerImplFiles})
    get_filename_component(_target_file "${_src}" NAME)
    message(
      STATUS
      "Creating server_impl symlink: ${_cybld}/thrift/python/server_impl/${_target_file} -> ${_src}"
    )
    add_custom_command(
      TARGET
      create_binding_symlink_server_impl
      PRE_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_cybld}/thrift/python/server_impl/${_target_file}"
    )
  endforeach()

  # Create symlinks for server_impl/interceptor/*.pxd
  file(GLOB ServerImplInterceptorFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/python/server/interceptor/*.pxd"
    "${CMAKE_CURRENT_SOURCE_DIR}/python/server/interceptor/*.pyx"
  )

  foreach(_src ${ServerImplInterceptorFiles})
    get_filename_component(_target_file "${_src}" NAME)
    message(
      STATUS
      "Creating server_impl/interceptor symlink: ${_cybld}/thrift/python/server_impl/interceptor/${_target_file} -> ${_src}"
    )
    add_custom_command(
      TARGET
      create_binding_symlink_server_impl
      PRE_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_cybld}/thrift/python/server_impl/interceptor/${_target_file}"
    )
  endforeach()

  # Create server_impl/__init__.py with import hook (runtime)
  file(WRITE "${_cybld}/thrift/python/server_impl/__init__.py" [=[
"""
OSS compatibility shim: thrift.python.server_impl -> thrift.python.server

Internal Buck builds use package remapping. OSS CMake builds use this
import hook to redirect server_impl imports to server modules.
"""
import sys
import importlib
import importlib.abc
import importlib.machinery
import importlib.util


class _ServerImplFinder(importlib.abc.MetaPathFinder):
    """Redirect thrift.python.server_impl.* to thrift.python.server.*"""

    def find_spec(self, fullname, path, target=None):
        if not fullname.startswith("thrift.python.server_impl."):
            return None
        real_name = fullname.replace(".server_impl.", ".server.")
        real_spec = importlib.util.find_spec(real_name)
        if real_spec is None:
            return None
        return importlib.machinery.ModuleSpec(
            fullname,
            _ServerImplLoader(real_name),
            origin=real_spec.origin,
            is_package=real_spec.submodule_search_locations is not None,
        )


class _ServerImplLoader(importlib.abc.Loader):
    def __init__(self, real_name):
        self.real_name = real_name

    def create_module(self, spec):
        real_module = importlib.import_module(self.real_name)
        sys.modules[spec.name] = real_module
        return real_module

    def exec_module(self, module):
        pass


sys.meta_path.insert(0, _ServerImplFinder())
]=])

  # Create empty __init__.py for interceptor subpackage
  file(WRITE "${_cybld}/thrift/python/server_impl/interceptor/__init__.py" "")

  #####
  # Now build everything else in lib/python, including all remaining Cython
  # modules that depend on types_api.h and thrift_python_cpp.
  #####
  add_custom_target(
    thrift_python_and_py3_bindings ALL
    DEPENDS
      generate_apache_thrift_metadata_python
      generate_apache_thrift_metadata_py3
      create_binding_symlink_python
      create_binding_symlink_py3
      create_binding_symlink_server_impl
      thriftcpp2
      thrift_python_cpp
      thrift_python_types_bindings
    WORKING_DIRECTORY ${_cybld}
  )

  set(inc_dirs "$<TARGET_PROPERTY:thrift,INCLUDE_DIRECTORIES>")
  get_target_property(fmt_include_dirs fmt::fmt INTERFACE_INCLUDE_DIRECTORIES)
  get_target_property(wangle_incs wangle::wangle INTERFACE_INCLUDE_DIRECTORIES)
  get_target_property(thrift_include_dirs thrift INCLUDE_DIRECTORIES)
  get_target_property(glog_include_dirs glog::glog INTERFACE_INCLUDE_DIRECTORIES)
  list(JOIN wangle_incs ":" wangle_include_dirs)
  set(incs "-I$<JOIN:${inc_dirs},:>:${FOLLY_INCLUDE_DIR}:${Boost_INCLUDE_DIRS}:${fmt_include_dirs}:${wangle_include_dirs}:${CMAKE_BINARY_DIR}/thrift/lib:${CMAKE_BINARY_DIR}/thrift/lib/cybld")
  get_filename_component(python_libname ${PYTHON_LIBRARY} NAME)

  # Create colon-separated include path for CYTHON_INCLUDE_PATH (same as incs but for env var)
  # Collect all include directories into a single list first, then join with colons
  # (embedding list variables directly in strings causes semicolon-separation, not colon-separation)
  set(_all_cython_includes
    ${thrift_include_dirs}
    ${FOLLY_INCLUDE_DIR}
    ${FOLLY_PYTHON_SITE_PACKAGES}
    ${Boost_INCLUDE_DIRS}
    ${fmt_include_dirs}
    ${wangle_incs}
    ${glog_include_dirs}
    ${CMAKE_BINARY_DIR}/thrift/lib
    ${CMAKE_BINARY_DIR}/thrift/lib/cybld
  )
  list(JOIN _all_cython_includes ":" cython_include_path)


  # Auto-discover all library directories from getdeps installed packages
  # This ensures setup.py's find_static_lib() can find ALL libraries in static_lib_names
  get_filename_component(GETDEPS_INSTALL_ROOT "${CMAKE_INSTALL_PREFIX}/.." ABSOLUTE)
  file(GLOB installed_packages "${GETDEPS_INSTALL_ROOT}/*")
  set(all_lib_dirs "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
  foreach(pkg ${installed_packages})
    if(EXISTS "${pkg}/lib")
      list(APPEND all_lib_dirs "${pkg}/lib")
    endif()
    if(EXISTS "${pkg}/lib64")
      list(APPEND all_lib_dirs "${pkg}/lib64")
    endif()
  endforeach()
  # Add system library paths
  list(APPEND all_lib_dirs "/usr/lib64")
  # Add python library directory
  get_filename_component(python_lib ${PYTHON_LIBRARY} DIRECTORY)
  list(APPEND all_lib_dirs "${python_lib}")

  # Join all library directories with colons for -L flags and LIBRARY_DIRS
  list(JOIN all_lib_dirs ":" library_dirs_str)
  set(libs "-L${library_dirs_str}")
  set(py_install_dir ${CMAKE_INSTALL_PREFIX})
  if (NOT ${PYTHON_PACKAGE_INSTALL_DIR} STREQUAL "")
    set(py_install_dir ${PYTHON_PACKAGE_INSTALL_DIR})
  endif()

  # Set default LDFLAGS for setup.py to fix undefined symbol issues
  # --no-as-needed ensures libfolly.so is in NEEDED list even if linker thinks it's not needed
  set(DEFAULT_SETUP_LDFLAGS "-Wl,--no-as-needed")

  # Allow users to override via environment variable (e.g., for custom RPATH)
  if(DEFINED ENV{LDFLAGS})
    set(SETUP_LDFLAGS "$ENV{LDFLAGS}")
    message(STATUS "Using user-provided LDFLAGS: ${SETUP_LDFLAGS}")
  else()
    set(SETUP_LDFLAGS "${DEFAULT_SETUP_LDFLAGS}")
    message(STATUS "Using default LDFLAGS: ${SETUP_LDFLAGS}")
  endif()

  # Pass include paths to Cython via environment variable for build_ext phase
  # (needed for cythonize to find folly .pxd files)
  add_custom_command(TARGET thrift_python_and_py3_bindings
    COMMAND ${CMAKE_COMMAND} -E env
      "CFLAGS=${CMAKE_C_FLAGS}"
      "CXXFLAGS=${CMAKE_CXX_FLAGS}"
      "CXX=${CMAKE_CXX_COMPILER}"
      "LDFLAGS=${SETUP_LDFLAGS}"
      "CYTHON_INCLUDE_PATH=${cython_include_path}"
      "LIBRARY_DIRS=${library_dirs_str}"
      python3 ${CMAKE_CURRENT_SOURCE_DIR}/setup.py -v
      build_ext -f ${incs} ${libs} --libpython ${python_libname}
    WORKING_DIRECTORY ${_cybld}
  )
  add_custom_command(TARGET thrift_python_and_py3_bindings
    COMMAND ${CMAKE_COMMAND} -E env
      "CFLAGS=${CMAKE_C_FLAGS}"
      "CXXFLAGS=${CMAKE_CXX_FLAGS}"
      "CXX=${CMAKE_CXX_COMPILER}"
      python3 ${CMAKE_CURRENT_SOURCE_DIR}/setup.py -v
      bdist_wheel --libpython ${python_libname}
    WORKING_DIRECTORY ${_cybld}
  )
  add_custom_command(TARGET thrift_python_and_py3_bindings POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env
      "CFLAGS=${CMAKE_C_FLAGS}"
      "CXXFLAGS=${CMAKE_CXX_FLAGS}"
      "CXX=${CMAKE_CXX_COMPILER}"
      python3 ${CMAKE_CURRENT_SOURCE_DIR}/setup.py -v
      install --prefix ${CMAKE_INSTALL_PREFIX} --libpython ${python_libname}
    WORKING_DIRECTORY ${_cybld}
  )

  # getdeps.py does not allow sufficient control of CMAKE_INSTALL_PREFIX,
  # so PYTHON_PACKAGE_INSTALL_DIR can be used to control the installation
  # location of Python packages.
  set(ENV{CXX} ${CMAKE_CXX_COMPILER})
  install(CODE "
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E env
        \"CFLAGS=${CMAKE_C_FLAGS}\"
        \"CXXFLAGS=${CMAKE_CXX_FLAGS}\"
        python3 ${CMAKE_CURRENT_SOURCE_DIR}/setup.py install -v
        --prefix ${py_install_dir} --libpython ${python_libname}
      COMMAND_ECHO STDOUT
      WORKING_DIRECTORY ${_cybld}
    )
  ")
endif()

set(LIB_DIRS
  thrift
  cpp
  cpp2
  python
  py3
)
foreach(dir ${LIB_DIRS})
  install(DIRECTORY ${dir} "${CMAKE_CURRENT_BINARY_DIR}/${dir}"
        DESTINATION include/thrift/lib
        FILES_MATCHING
          PATTERN "*.h"
          PATTERN "*.tcc"
          PATTERN CMakeFiles EXCLUDE)
endforeach()
