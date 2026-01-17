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

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# FOLLY_INCLUDE_DIR is exported by folly-config.cmake (set by find_package)
# Used by setup.py to locate folly .pxd files during Cython compilation
message(STATUS "FOLLY_INCLUDE_DIR: ${FOLLY_INCLUDE_DIR}")

# Set FOLLY_PYTHON_SITE_PACKAGES for Cython .pxd files (folly.pxd, iobuf.pxd, etc.)
# These are separate from C++ headers and live in Python site-packages
# Note: pip --prefix on Debian/Ubuntu installs to local/lib/pythonX.Y/dist-packages/
# while setup.py install goes to lib/pythonX.Y/site-packages/
# Check both locations to handle different folly build methods
set(_folly_py_version "python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}")
set(_folly_site_packages "${FOLLY_PREFIX_DIR}/lib/${_folly_py_version}/site-packages")
set(_folly_dist_packages "${FOLLY_PREFIX_DIR}/local/lib/${_folly_py_version}/dist-packages")

if(EXISTS "${_folly_site_packages}/folly")
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_site_packages}")
  message(STATUS "FOLLY_PYTHON_SITE_PACKAGES: ${FOLLY_PYTHON_SITE_PACKAGES} (site-packages)")
elseif(EXISTS "${_folly_dist_packages}/folly")
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_dist_packages}")
  message(STATUS "FOLLY_PYTHON_SITE_PACKAGES: ${FOLLY_PYTHON_SITE_PACKAGES} (dist-packages)")
else()
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_site_packages}")
  message(WARNING
    "Folly Python package not found at ${_folly_site_packages}/folly or "
    "${_folly_dist_packages}/folly. Cython compilation may fail."
  )
endif()


find_package(Cython 0.28 REQUIRED)
find_package(proxygen CONFIG REQUIRED)


# thrift-python and py3 build logic
# NOTE: py3 is tightly coupled with python and is handled in this file.
# They cannot be separated into independent add_subdirectory() calls.

# Reference to parent lib directory for sibling directories (py3/) and setup.py
get_filename_component(_lib_dir "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
# Debug option for build troubleshooting
option(DEBUG_BUILD "Enable debug messages" OFF)

# Find libevent for Python bindings (needed for folly Python extensions)
# Force static linking to embed symbols into libthrift_python_cpp.so
# From LibeventConfig.cmake: "To find the static ones instead, you must set
# the LIBEVENT_STATIC_LINK variable to TRUE before calling find_package"
set(LIBEVENT_STATIC_LINK TRUE)
find_package(Libevent REQUIRED CONFIG)

# Find libiberty (provides cplus_demangle_v3_callback needed by folly)
find_package(Libiberty REQUIRED)

# NOTE: Do NOT add gflags here. glog::glog (shared) depends on
# gflags (shared). If we embed gflags_static AND glog loads
# gflags_shared at runtime = conflict.
# Let glog's dependency chain provide gflags at runtime.

function(log_debug msg)
  if(DEBUG_BUILD)
    message(STATUS "[DEBUG] ${msg}")
  endif()
endfunction()

# Use parent binary dir so _cybld stays at <build>/thrift/lib/cybld
# (consistent with include paths like thrift/lib/python/server/*.h)
get_filename_component(_cybld "${CMAKE_CURRENT_BINARY_DIR}/../cybld" ABSOLUTE)
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

# Helper function: filter exclusion list for a specific subdirectory
# Given a list of "relpath/filename" exclusions and a target relpath,
# returns filenames that should be excluded for that directory
# Result is stored in variable named by out_var
function(get_exclusions_for_dir out_var target_relpath)
  set(_result "")
  foreach(_excl ${ARGN})
    get_filename_component(_excl_dir "${_excl}" DIRECTORY)
    get_filename_component(_excl_filename "${_excl}" NAME)
    if("${_excl_dir}" STREQUAL "${target_relpath}")
      list(APPEND _result "${_excl_filename}")
    endif()
  endforeach()
  set(${out_var} ${_result} PARENT_SCOPE)
endfunction()

# Helper function: symlink all source files from a directory to build dir
# Non-recursive - only files directly in the directory
# (subdirs handled separately)
# Optional ARGN: list of filenames to exclude from symlinking
function(symlink_dir_contents src_dir dest_dir)
  file(MAKE_DIRECTORY "${dest_dir}")
  file(GLOB _all_items "${src_dir}/*")

  # Collect exclusion list from optional arguments
  set(_exclude_list ${ARGN})

  foreach(_src ${_all_items})
    if(IS_DIRECTORY "${_src}")
      continue()
    endif()

    get_filename_component(_filename "${_src}" NAME)

    # Skip files in exclusion list
    if(_filename IN_LIST _exclude_list)
      message(STATUS "Skipping excluded file: ${_src}")
      continue()
    endif()

    set(_dest "${dest_dir}/${_filename}")

    message(STATUS "Symlinking ${_src} -> ${_dest}")
    file(CREATE_LINK "${_src}" "${_dest}" SYMBOLIC)
  endforeach()
endfunction()

# Helper function: recursively symlink all files from a source tree
# to build directory. Calls symlink_dir_contents for each directory.
# Optional ARGN: list of "relpath/filename" exclusions (e.g., "streaming/bidistream.cpp")
function(symlink_dir_recursive src_dir dest_base_dir)
  # Parse exclusion list from optional arguments
  set(_exclusion_list ${ARGN})

  # Handle the root directory (root = empty relpath)
  get_exclusions_for_dir(_root_exclusions "" ${_exclusion_list})
  symlink_dir_contents("${src_dir}" "${dest_base_dir}" ${_root_exclusions})

  # Find all subdirectories and call symlink_dir_contents for each
  file(GLOB_RECURSE _all_subdirs LIST_DIRECTORIES true
    "${src_dir}/*")

  foreach(_src_dir ${_all_subdirs})
    if(IS_DIRECTORY "${_src_dir}")
      file(RELATIVE_PATH _rel "${src_dir}" "${_src_dir}")
      get_exclusions_for_dir(_subdir_exclusions "${_rel}" ${_exclusion_list})
      symlink_dir_contents("${src_dir}/${_rel}" "${dest_base_dir}/${_rel}" ${_subdir_exclusions})
    endif()
  endforeach()
endfunction()

# Symlink all python/ and py3/ source files recursively
# Exclude streaming/bidistream.cpp - it's symlinked separately as Bidistream.cpp
# to avoid Cython conflict (bidistream.pyx generates bidistream.cpp)
symlink_dir_recursive("${CMAKE_CURRENT_SOURCE_DIR}" "${_cybld}/thrift/python" "streaming/bidistream.cpp")
symlink_dir_recursive("${_lib_dir}/py3" "${_cybld}/thrift/py3")

# Special case: bidistream.cpp needs to be symlinked with capital B to avoid
# Cython conflict (bidistream.pyx would generate bidistream.cpp, conflicting
# with handwritten bidistream.cpp). Sink.cpp and PythonUserException.cpp work
# fine because their capital letters differ from lowercase .pyx names.
file(CREATE_LINK
  "${CMAKE_CURRENT_SOURCE_DIR}/streaming/bidistream.cpp"
  "${_cybld}/thrift/python/streaming/Bidistream.cpp"
  SYMBOLIC)

# Placeholder targets for build dependency tracking
# Symlinks are created at configure time by symlink_dir_recursive above,
# but other parts of the build depend on these targets for ordering.
add_custom_target(create_binding_symlink_python ALL)
add_custom_target(create_binding_symlink_py3 ALL)

#####################################################################
# Include Path Setup (must be done early, before API header generation)
#####################################################################
get_target_property(thrift_include_dirs thrift INCLUDE_DIRECTORIES)
get_target_property(fmt_include_dirs fmt::fmt INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(wangle_incs wangle::wangle INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(
  glog_include_dirs glog::glog INTERFACE_INCLUDE_DIRECTORIES)

# For setup.py build_ext -I flags
set(inc_dirs "$<TARGET_PROPERTY:thrift,INCLUDE_DIRECTORIES>")
list(JOIN wangle_incs ":" wangle_include_dirs)
string(CONCAT incs
  "-I$<JOIN:${inc_dirs},:>"
  ":${FOLLY_INCLUDE_DIR}"
  ":${Boost_INCLUDE_DIRS}"
  ":${fmt_include_dirs}"
  ":${wangle_include_dirs}"
  ":${CMAKE_BINARY_DIR}/thrift/lib"
  ":${CMAKE_BINARY_DIR}/thrift/lib/cybld"
)
get_filename_component(python_libname ${Python3_LIBRARIES} NAME)

# Create colon-separated include path for CYTHON_INCLUDE_PATH env var
# Proxygen and mvfst include directories (for http2_helper in client tests)
# Derive from cmake targets (found via find_package above) - not hardcoded paths
get_target_property(proxygen_incs proxygen::proxygen INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(mvfst_incs mvfst::mvfst_transport INTERFACE_INCLUDE_DIRECTORIES)

set(_all_cython_includes
  # Thrift includes
  ${thrift_include_dirs}
  ${CMAKE_BINARY_DIR}/thrift/lib
  ${CMAKE_BINARY_DIR}/thrift/lib/cybld
  # Folly includes (including .pxd files)
  ${FOLLY_INCLUDE_DIR}
  ${FOLLY_PYTHON_SITE_PACKAGES}
  # Boost
  ${Boost_INCLUDE_DIRS}
  # Other dependencies
  ${fmt_include_dirs}
  ${wangle_incs}
  ${glog_include_dirs}
  # Proxygen and mvfst (for http2_helper.pyx client tests)
  ${proxygen_incs}
  ${mvfst_incs}
)
list(JOIN _all_cython_includes ":" cython_include_path)
log_debug("cython_include_path='${cython_include_path}'")

#####################################################################
# Library Path Setup
#####################################################################
# Auto-discover all library directories from getdeps installed packages
# This ensures setup.py's find_static_lib() can find ALL libraries
# in static_lib_names. Use GETDEPS_INSTALL_DIR env var if set (getdeps
# always sets this), otherwise fall back to deriving from
# CMAKE_INSTALL_PREFIX (works when CMAKE_INSTALL_PREFIX is in the
# getdeps installed directory, but NOT when --project-install-prefix
# overrides it)
if(DEFINED ENV{GETDEPS_INSTALL_DIR})
  set(GETDEPS_INSTALL_ROOT "$ENV{GETDEPS_INSTALL_DIR}")
else()
  get_filename_component(
    GETDEPS_INSTALL_ROOT "${CMAKE_INSTALL_PREFIX}/.." ABSOLUTE)
endif()
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
list(APPEND all_lib_dirs "/usr/lib64")
get_filename_component(python_lib ${Python3_LIBRARIES} DIRECTORY)
list(APPEND all_lib_dirs "${python_lib}")

# Join all library directories with colons for -L flags and LIBRARY_DIRS
list(JOIN all_lib_dirs ":" library_dirs_str)
set(libs "-L${library_dirs_str}")

#####################################################################
# Install Directory
#####################################################################
set(py_install_dir ${CMAKE_INSTALL_PREFIX})
if (NOT ${PYTHON_PACKAGE_INSTALL_DIR} STREQUAL "")
  set(py_install_dir ${PYTHON_PACKAGE_INSTALL_DIR})
endif()

#####################################################################
# Linker Flags
#####################################################################
# Set default LDFLAGS for setup.py to fix undefined symbol issues
# --no-as-needed ensures libfolly.so is in NEEDED list even if linker
# thinks it's not needed
set(DEFAULT_SETUP_LDFLAGS "-Wl,--no-as-needed")

# Allow users to override via environment variable (e.g., for custom RPATH)
if(DEFINED ENV{LDFLAGS})
  set(SETUP_LDFLAGS "$ENV{LDFLAGS}")
  message(STATUS "Using user-provided LDFLAGS: ${SETUP_LDFLAGS}")
else()
  set(SETUP_LDFLAGS "${DEFAULT_SETUP_LDFLAGS}")
  message(STATUS "Using default LDFLAGS: ${SETUP_LDFLAGS}")
endif()

###
# First, run Thrift compiler on metadata.thrift. thrift-python runtime
# depends on apache.thrift.metadata package, which is created and
# installed later in setup.py.
###
add_custom_target(
  generate_apache_thrift_metadata_python
  COMMAND
    thrift1 -I ${CMAKE_SOURCE_DIR} --out .
    --gen "mstch_python:include_prefix=thrift"
    ${_lib_dir}/thrift/metadata.thrift
  COMMAND ${CMAKE_COMMAND} -E make_directory ${_cybld}/apache/thrift/metadata
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
# Also generate py3 version for apache.thrift.metadata
# (required by py3/metadata.pyx)
###
add_custom_target(
  generate_apache_thrift_metadata_py3
  COMMAND
    thrift1 -I ${CMAKE_SOURCE_DIR} --out .
    --gen "mstch_py3:include_prefix=thrift"
    ${_lib_dir}/thrift/metadata.thrift
  WORKING_DIRECTORY ${_cybld}
  BYPRODUCTS
    ${_cybld}/apache/thrift/metadata/cbindings.pxd
    ${_cybld}/apache/thrift/metadata/cbindings.pyx
    ${_cybld}/apache/thrift/metadata/metadata.pxd
    ${_cybld}/apache/thrift/metadata/metadata.pyx
)

####
# Next, prepare for building cython extensions by creating the necessary
# symlinks in the cybld directory
####
add_custom_target(create_binding_symlink_python_types ALL)
# Python types files (local to this directory)
foreach(_file "types.pxd" "types.pyx")
  set(_src "${CMAKE_CURRENT_SOURCE_DIR}/${_file}")
  get_filename_component(_target_file "${_src}" NAME)
  message(STATUS "Linking ${_src} to ${_cybld}/thrift/python/_${_target_file}")
  add_custom_command(
    TARGET create_binding_symlink_python_types PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      "${_src}" "${_cybld}/thrift/python/_${_target_file}"
  )
endforeach()
# py3 stream files (in sibling py3 directory)
foreach(_file "stream.pxd" "stream.pyx")
  set(_src "${_lib_dir}/py3/${_file}")
  get_filename_component(_target_file "${_src}" NAME)
  message(STATUS "Linking ${_src} to ${_cybld}/thrift/py3/_${_target_file}")
  add_custom_command(
    TARGET create_binding_symlink_python_types PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      "${_src}" "${_cybld}/thrift/py3/_${_target_file}"
  )
endforeach()
# Below symlinks simplify cythonize logic in setup.py
add_custom_command(
  TARGET
  create_binding_symlink_python_types
  PRE_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/server/server.pxd"
    "${_cybld}/thrift/python/server.pxd"
)
add_custom_command(
  TARGET
  create_binding_symlink_python_types
  PRE_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/thrift/python/server/server.pyx"
    "${_cybld}/thrift/python/server.pyx"
)

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

log_debug(
  "At API header generation: cython_include_path='${cython_include_path}'")

add_custom_command(
  OUTPUT ${CYTHON_GENERATED_API_HEADERS}
  COMMAND ${CMAKE_COMMAND} -E env
    "CFLAGS=${CMAKE_C_FLAGS}"
    "CXXFLAGS=${CMAKE_CXX_FLAGS}"
    "CXX=${CMAKE_CXX_COMPILER}"
    "CYTHON_INCLUDE_PATH=${cython_include_path}"
    python3 ${_lib_dir}/setup.py -v --api-only
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

#####################################################################
# API Header Symlinks
#####################################################################
# WHY: C++ code includes headers as "thrift/lib/python/types_api.h"
#      but setup.py generates them at "thrift/python/_types_api.h"
#      Symlinks bridge this path difference.
#
# NOTE: server_impl in source paths (not server) because:
#       - C++ code expects
#         import_thrift__python__server_impl__python_async_processor
#       - Buck uses package = "thrift.python.server_impl"
#       - Must match the import function names in generated API headers

# Define all API header symlink mappings (source|destination)
set(CYTHON_API_SYMLINK_MAPPINGS
  "${_cybld}/thrift/python/_types_api.h|\
${_cybld}/thrift/lib/python/types_api.h"
  "${_cybld}/thrift/python/_types.h|${_cybld}/thrift/lib/python/_types.h"
  "${_cybld}/thrift/python/server_impl/python_async_processor_api.h|\
${_cybld}/thrift/lib/python/server/python_async_processor_api.h"
  "${_cybld}/thrift/python/server_impl/request_context_api.h|\
${_cybld}/thrift/lib/python/server/request_context_api.h"
  "${_cybld}/thrift/python/server_impl/interceptor/service_interceptor_api.h|\
${_cybld}/thrift/lib/python/server/interceptor/service_interceptor_api.h"
  "${_cybld}/thrift/py3/_stream_api.h|${_cybld}/thrift/lib/py3/stream_api.h"
  "${_cybld}/thrift/py3/_stream.h|${_cybld}/thrift/lib/py3/_stream.h"
  "${_cybld}/thrift/python/streaming/sink_api.h|\
${_cybld}/thrift/lib/python/streaming/sink_api.h"
  "${_cybld}/thrift/python/streaming/bidistream_api.h|\
${_cybld}/thrift/lib/python/streaming/bidistream_api.h"
  "${_cybld}/thrift/python/streaming/py_promise_api.h|\
${_cybld}/thrift/lib/python/streaming/py_promise_api.h"
)

# Generate symlink commands from mappings
set(CYTHON_API_SYMLINKS "")
set(SYMLINK_COMMANDS "")
foreach(mapping IN LISTS CYTHON_API_SYMLINK_MAPPINGS)
  string(REPLACE "|" ";" pair ${mapping})
  list(GET pair 0 source)
  list(GET pair 1 dest)
  list(APPEND CYTHON_API_SYMLINKS ${dest})
  list(APPEND SYMLINK_COMMANDS
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${dest})
endforeach()

file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/")
file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/server")
file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/server/interceptor")
file(MAKE_DIRECTORY "${_cybld}/thrift/lib/python/streaming")
file(MAKE_DIRECTORY "${_cybld}/thrift/lib/py3/")

# Create all symlinks
# (OUTPUT ensures files exist before dependent targets build)
add_custom_command(
  OUTPUT ${CYTHON_API_SYMLINKS}
  ${SYMLINK_COMMANDS}
  DEPENDS ${CYTHON_GENERATED_API_HEADERS}
  COMMENT "Creating symlinks to Cython API headers"
)

# Target for dependency tracking
add_custom_target(
  create_cython_types_api_symlink ALL
  DEPENDS ${CYTHON_API_SYMLINKS}
)
# Explicit target-level dependency: symlinks wait for API headers
add_dependencies(create_cython_types_api_symlink thrift_python_types_bindings)

# SHARED to reduce build time, disk space, and runtime memory
add_library(
  thrift_python_cpp SHARED
    client/OmniClient.cpp
    client/RequestChannel.cpp
    client/ssl.cpp
    Serializer.cpp
    server/event_handler.cpp
    server/flagged/RcAwareTaskPatch.cpp
    server/interceptor/PythonServiceInterceptor.cpp
    server/PythonAsyncProcessor.cpp
    server/PythonAsyncProcessorFactory.cpp
    server/RequestContextExtractor.cpp
    std_libcpp.cpp
    streaming/bidistream.cpp
    streaming/PythonUserException.cpp
    streaming/Sink.cpp
    streaming/StreamElementEncoder.cpp
    types.cpp
    ${_lib_dir}/py3/stream.cpp
)
add_dependencies(thrift_python_cpp create_cython_types_api_symlink)
set_property(TARGET thrift_python_cpp PROPERTY VERSION ${PACKAGE_VERSION})
target_compile_definitions(thrift_python_cpp PRIVATE BOOST_NO_AUTO_PTR)
target_compile_definitions(
  thrift_python_cpp PRIVATE THRIFT_NO_HTTP_CLIENT_CHANNEL)
target_include_directories(
  thrift_python_cpp PRIVATE "${_cybld}" ${Python3_INCLUDE_DIRS})
# Link strategy:
# - STATIC libs (thrift + deps): embed with --whole-archive to consolidate
#   into single .so
# - SHARED libs (folly, fmt, glog): link normally, become runtime deps
# --allow-multiple-definition handles duplicate symbols across static libs
# (e.g., librpcmetadata.a and libthriftprotocol.a both compile
# TJSONProtocol.cpp)
# libevent/libiberty: needed for undefined symbols,
# --allow-multiple-definition handles duplicates
target_link_libraries(
  thrift_python_cpp
  PUBLIC
    # Static libs - embed all symbols
    "-Wl,--whole-archive"
    "-Wl,--allow-multiple-definition"
    thriftcpp2
    rpcmetadata
    thriftannotation
    thriftmetadata
    thriftfrozen2
    thriftprotocol
    thrifttyperep
    thrifttype
    thriftanyrep
    serverdbginfo
    libevent::core
    libevent::extra
    ${LIBIBERTY_LIBRARIES}
    "-Wl,--no-whole-archive"
    # Shared libs - runtime deps (see manifests/folly, manifests/fmt)
    Folly::folly
    Folly::folly_python_cpp
    fmt::fmt
    glog::glog
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

file(MAKE_DIRECTORY "${_cybld}/thrift/python/server_impl")
file(MAKE_DIRECTORY "${_cybld}/thrift/python/server_impl/interceptor")

# For cimport during Cython compilation
file(GLOB ServerImplFiles
  "${CMAKE_CURRENT_SOURCE_DIR}/server/*.pxd"
  "${CMAKE_CURRENT_SOURCE_DIR}/server/*.pyx"
)

foreach(_src ${ServerImplFiles})
  get_filename_component(_target_file "${_src}" NAME)
  message(
    STATUS
    "Creating server_impl symlink: \
${_cybld}/thrift/python/server_impl/${_target_file} -> ${_src}"
  )
  add_custom_command(
    TARGET
    create_binding_symlink_server_impl
    PRE_BUILD
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      "${_src}" "${_cybld}/thrift/python/server_impl/${_target_file}"
  )
endforeach()

# Create symlinks for server_impl/interceptor/*.pxd
file(GLOB ServerImplInterceptorFiles
  "${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/*.pxd"
  "${CMAKE_CURRENT_SOURCE_DIR}/server/interceptor/*.pyx"
)

foreach(_src ${ServerImplInterceptorFiles})
  get_filename_component(_target_file "${_src}" NAME)
  message(
    STATUS
    "Creating server_impl/interceptor symlink: \
${_cybld}/thrift/python/server_impl/interceptor/${_target_file} -> ${_src}"
  )
  add_custom_command(
    TARGET
    create_binding_symlink_server_impl
    PRE_BUILD
      COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      "${_src}"
      "${_cybld}/thrift/python/server_impl/interceptor/${_target_file}"
  )
endforeach()

#####
# Generate thrift-python test types
#####
add_subdirectory(test)

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
    create_binding_symlink_lib_test
    thriftcpp2
    thrift_python_cpp
    thrift_python_types_bindings
  WORKING_DIRECTORY ${_cybld}
)

# Copy folly Python bindings into the build directory before wheel creation.
# Folly doesn't build a wheel yet, so we bundle folly.iobuf, folly.executor,
# etc. into the thrift wheel so users don't need to install folly separately.
add_custom_command(TARGET thrift_python_and_py3_bindings
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${FOLLY_PYTHON_SITE_PACKAGES}/folly"
    "${_cybld}/folly"
  COMMENT "Copying folly Python bindings into wheel build directory"
)
add_custom_command(TARGET thrift_python_and_py3_bindings
  COMMAND ${CMAKE_COMMAND} -E env
    "CFLAGS=${CMAKE_C_FLAGS}"
    "CXXFLAGS=${CMAKE_CXX_FLAGS}"
    "CXX=${CMAKE_CXX_COMPILER}"
    "LDFLAGS=${SETUP_LDFLAGS}"
    "CYTHON_INCLUDE_PATH=${cython_include_path}"
    "LIBRARY_DIRS=${library_dirs_str}"
    "THRIFT_BUILD_TESTS=${THRIFT_BUILD_TESTS}"
    python3 ${_lib_dir}/setup.py -v
    bdist_wheel --libpython ${python_libname}
  WORKING_DIRECTORY ${_cybld}
)

# Run auditwheel repair to make the wheel self-contained
# This bundles .so dependencies and rewrites RPATH to $ORIGIN
# LD_LIBRARY_PATH tells auditwheel where to find the libraries to bundle
add_custom_command(TARGET thrift_python_and_py3_bindings
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_cybld}/dist_self_contained"
  COMMAND ${CMAKE_COMMAND} -E env
    "LD_LIBRARY_PATH=${library_dirs_str}"
    python3 -m auditwheel repair
    --wheel-dir "${_cybld}/dist_self_contained"
    "${_cybld}/dist/*.whl"
  WORKING_DIRECTORY ${_cybld}
)

# Install the self-contained wheel to the install prefix for users to pip install
# The wheel is processed by auditwheel to ${_cybld}/dist_self_contained/
install(
  DIRECTORY "${_cybld}/dist_self_contained/"
  DESTINATION share/thrift/wheels
  FILES_MATCHING PATTERN "*.whl"
)
