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

# Generate thrift-python test types

set(TEST_THRIFT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PY3_TEST_THRIFT_DIR ${CMAKE_SOURCE_DIR}/thrift/lib/py3/test)

# Files from py3/test needed by thrift-python tests (no namespace in thrift file)
# Output goes to gen-python/binary/, gen-python/iobuf/ etc.
thrift_library(
  "binary"
  "BinaryService"
  "python"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

thrift_library(
  "iobuf"
  "IobufTestService"
  "python"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

# derived.thrift - no py3 namespace, includes testing.thrift
thrift_library(
  "derived"
  "DerivedTestingService"
  "python"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

# convertible.thrift - no py3 namespace
thrift_library(
  "convertible"
  ""
  "python"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

# stack_args.thrift - no py3 namespace
thrift_library(
  "stack_args"
  "StackService"
  "python"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

set(THRIFT_TEST_DIR ${CMAKE_SOURCE_DIR}/thrift/test)
thrift_library(
  "schema_evolution_test"
  ""
  "python"
  ""
  "${THRIFT_TEST_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
)

# Files with namespace py3 "testing"
thrift_library(
  "testing"
  "TestingService;TestingServiceChild;ExtendServiceWithNoTypes;ClientMetadataTestingService"
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "base_service_only"
  "BaseService"
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "dependency"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "sub_dependency"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "injected_field"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "py_deprecated_asyncio_test"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "py_deprecated_asyncio_fallback_test"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

thrift_library(
  "test_inject_metadata_fields"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing"
)

# Files with namespace py3 "python_test"
thrift_library(
  "adapter"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "containers"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "enums"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "enums_typedef_only"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "lists"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "maps"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "refs"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

thrift_library(
  "sets"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "python_test"
)

# Files with namespace py3 "thrift.python"
thrift_library(
  "bidi_service"
  "TestBidiService"
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python"
)

thrift_library(
  "sink_service"
  "TestSinkService"
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python"
)

# Files with namespace py3 "thrift.python.test"
thrift_library(
  "special_cases"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python.test"
)

# Files without namespace py3 - use empty namespace (output to gen-python/<file_name>/)
thrift_library(
  "abstract_types_flags"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python.test"
)

thrift_library(
  "annotations"
  ""
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python.test"
)

set(THRIFT_PYTHON_TEST_DIR "${CMAKE_SOURCE_DIR}/thrift/test/thrift-python")

thrift_library(
  "struct_test"
  ""
  "python"
  ""
  "${THRIFT_PYTHON_TEST_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.test.thrift_python"
)

thrift_library(
  "union_test"
  ""
  "python"
  ""
  "${THRIFT_PYTHON_TEST_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.test.thrift_python"
)

thrift_library(
  "enum_test"
  ""
  "python"
  ""
  "${THRIFT_PYTHON_TEST_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.test.thrift_python"
)

thrift_library(
  "included"
  ""
  "python"
  ""
  "${THRIFT_PYTHON_TEST_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.test.thrift_python"
)

# transitive_deps thrift files - from py3/test/transitive_deps/
# namespace py3 transitive_deps -> output to transitive_deps/a/, transitive_deps/b/, etc.
set(TRANSITIVE_DEPS_DIR ${CMAKE_SOURCE_DIR}/thrift/lib/py3/test/transitive_deps)

thrift_library(
  "a"
  ""
  "python"
  ""
  "${TRANSITIVE_DEPS_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "transitive_deps"
)

thrift_library(
  "b"
  ""
  "python"
  ""
  "${TRANSITIVE_DEPS_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "transitive_deps"
)

thrift_library(
  "c"
  ""
  "python"
  ""
  "${TRANSITIVE_DEPS_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "transitive_deps"
)

thrift_library(
  "d"
  ""
  "python"
  ""
  "${TRANSITIVE_DEPS_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "transitive_deps"
)

# terse_write.thrift - from thrift/test/terse_write/
# namespace py3 apache.thrift.test.terse_write -> output to apache/thrift/test/terse_write/terse_write/
set(TERSE_WRITE_DIR ${CMAKE_SOURCE_DIR}/thrift/test/terse_write)

thrift_library(
  "terse_write"
  ""
  "python"
  ""
  "${TERSE_WRITE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "apache.thrift.test.terse_write"
)

# client/test thrift files (test.thrift, leaf.thrift)
# Namespace py3 "thrift.python" means output goes to thrift/python/test/ and thrift/python/leaf/
set(CLIENT_TEST_THRIFT_DIR "${CMAKE_SOURCE_DIR}/thrift/lib/python/client/test")

# test.thrift - defines TestService, EchoService
thrift_library(
  "test"
  "TestService;EchoService"
  "python"
  ""
  "${CLIENT_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python"
)

# leaf.thrift - defines LeafService (extends EchoService from test.thrift)
thrift_library(
  "leaf"
  "LeafService"
  "python"
  ""
  "${CLIENT_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "thrift.python"
)

#####
# Create symlinks for test namespaces
# gen-python/<namespace>/ -> cybld/<namespace>/
#####
set(_cybld "${CMAKE_BINARY_DIR}/thrift/lib/cybld/build/lib.linux-${CMAKE_HOST_SYSTEM_PROCESSOR}-cpython-${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}")
set(_gen_python "${CMAKE_CURRENT_BINARY_DIR}/gen-python")

# Helper function: create symlink from gen-python to cybld
function(add_test_namespace_symlink name source_path target_path)
  add_custom_target(create_binding_symlink_${name} ALL
    DEPENDS ${ARGN}
  )
  add_custom_command(
    TARGET create_binding_symlink_${name}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${source_path}" "${target_path}"
  )
endfunction()

# Helper function: create multiple symlinks for one target
function(add_test_namespace_symlinks name)
  add_custom_target(create_binding_symlink_${name} ALL
    DEPENDS ${ARGN}
  )
endfunction()

function(add_symlink_command target_name source_path target_path)
  add_custom_command(
    TARGET create_binding_symlink_${target_name}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${source_path}" "${target_path}"
  )
endfunction()

# 1. testing namespace -> cybld/testing
add_test_namespace_symlink(testing
  "${_gen_python}/testing" "${_cybld}/testing"
  testing-python-target)

# 2. python_test namespace -> cybld/python_test
add_test_namespace_symlink(python_test
  "${_gen_python}/python_test" "${_cybld}/python_test"
  adapter-python-target containers-python-target enums-python-target
  lists-python-target maps-python-target refs-python-target sets-python-target)

# 3. thrift.test.thrift_python -> cybld/thrift/test
add_test_namespace_symlink(thrift_test
  "${_gen_python}/thrift/test" "${_cybld}/thrift/test"
  struct_test-python-target union_test-python-target enum_test-python-target included-python-target)

# 4. thrift.python.{bidi_service,sink_service} -> cybld/thrift/python/{bidi_service,sink_service}
add_test_namespace_symlinks(thrift_python_services bidi_service-python-target sink_service-python-target)
add_symlink_command(thrift_python_services "${_gen_python}/thrift/python/bidi_service" "${_cybld}/thrift/python/bidi_service")
add_symlink_command(thrift_python_services "${_gen_python}/thrift/python/sink_service" "${_cybld}/thrift/python/sink_service")

# 5. thrift.python.test.* -> cybld/thrift/python/test/*
add_test_namespace_symlinks(thrift_python_test special_cases-python-target abstract_types_flags-python-target annotations-python-target)
add_symlink_command(thrift_python_test "${_gen_python}/thrift/python/test/special_cases" "${_cybld}/thrift/python/test/special_cases")
add_symlink_command(thrift_python_test "${_gen_python}/thrift/python/test/abstract_types_flags" "${_cybld}/thrift/python/test/abstract_types_flags")
add_symlink_command(thrift_python_test "${_gen_python}/thrift/python/test/annotations" "${_cybld}/thrift/python/test/annotations")

# 5a. client/test thrift files: thrift.python.{test,leaf} -> cybld/thrift/python/{test,leaf}
# Note: These are test.thrift and leaf.thrift from python/client/test/ with namespace "thrift.python"
# The thrift compiler outputs files to gen-python/thrift/python/test/ and gen-python/thrift/python/leaf/
# The test/ directory already contains subdirectories (special_cases, etc.) so we symlink files, not the whole dir
# The leaf/ directory is new so we can symlink it directly
add_test_namespace_symlinks(thrift_python_client_test test-python-target leaf-python-target)

# For test/, symlink individual generated files (not the directory, since it has subdirs)
# These files are generated by client/test/test.thrift
set(_client_test_gen_files
  __init__.py
  thrift_abstract_types.py
  thrift_clients.py
  thrift_enums.py
  thrift_metadata.py
  thrift_mutable_clients.py
  thrift_mutable_services.py
  thrift_mutable_types.py
  thrift_mutable_types.pyi
  thrift_services.py
  thrift_types.py
  thrift_types.pyi
)
foreach(_file ${_client_test_gen_files})
  add_custom_command(
    TARGET create_binding_symlink_thrift_python_client_test
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      "${_gen_python}/thrift/python/test/${_file}"
      "${_cybld}/thrift/python/test/${_file}"
  )
endforeach()

# For leaf/, symlink the whole directory (no conflicts)
add_symlink_command(thrift_python_client_test "${_gen_python}/thrift/python/leaf" "${_cybld}/thrift/python/leaf")

# 6. binary and iobuf (no namespace) -> cybld/binary, cybld/iobuf
add_test_namespace_symlink(binary_direct
  "${_gen_python}/binary" "${_cybld}/binary"
  binary-python-target)

add_test_namespace_symlink(iobuf_direct
  "${_gen_python}/iobuf" "${_cybld}/iobuf"
  iobuf-python-target)

# 7. derived and convertible (no namespace) -> cybld/derived, cybld/convertible
add_test_namespace_symlink(derived_direct
  "${_gen_python}/derived" "${_cybld}/derived"
  derived-python-target)

add_test_namespace_symlink(convertible_direct
  "${_gen_python}/convertible" "${_cybld}/convertible"
  convertible-python-target)

add_test_namespace_symlink(stack_args_direct
  "${_gen_python}/stack_args" "${_cybld}/stack_args"
  stack_args-python-target)

add_test_namespace_symlink(schema_evolution_test_direct
  "${_gen_python}/schema_evolution_test" "${_cybld}/schema_evolution_test"
  schema_evolution_test-python-target)

# 8. transitive_deps namespace -> cybld/transitive_deps
add_test_namespace_symlink(transitive_deps
  "${_gen_python}/transitive_deps" "${_cybld}/transitive_deps"
  a-python-target b-python-target c-python-target d-python-target)

# 9. apache.thrift.test.terse_write namespace -> cybld/apache/thrift/test
# Note: cybld/apache/thrift/ already exists (for metadata), so we symlink test/ subdirectory
add_test_namespace_symlink(apache_thrift_test
  "${_gen_python}/apache/thrift/test" "${_cybld}/apache/thrift/test"
  terse_write-python-target)

# 10. apache.thrift.metadata namespace -> cybld/apache/thrift/metadata
# The metadata module is built by the main thrift library, we need to link it into gen-python
# so tests can import apache.thrift.metadata.thrift_types
add_custom_target(apache_thrift_metadata_symlink ALL
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld}/apache/thrift/metadata"
    "${_gen_python}/apache/thrift/metadata"
  DEPENDS terse_write-python-target
  COMMENT "Creating symlink for apache.thrift.metadata"
)

#####
# Make directories into Python packages
#####

include(${CMAKE_SOURCE_DIR}/PythonPackage.cmake)

# transitive_deps package
make_python_package(create_binding_symlink_transitive_deps "${_gen_python}/transitive_deps")

# apache namespace packages
add_custom_target(python_package_apache ALL
  DEPENDS terse_write-python-target
)
make_python_package(python_package_apache "${_gen_python}/apache")
make_python_package(python_package_apache "${_gen_python}/apache/thrift")

#####
# Python Test Definitions
#####

# Enable testing
enable_testing()

# Build PYTHONPATH for tests
set(TEST_PYTHONPATH "${_gen_python}:${_cybld}")

# Add folly python site-packages
if(DEFINED FOLLY_PYTHON_SITE_PACKAGES AND EXISTS "${FOLLY_PYTHON_SITE_PACKAGES}")
  set(TEST_PYTHONPATH "${TEST_PYTHONPATH}:${FOLLY_PYTHON_SITE_PACKAGES}")
endif()

# Add installed fbthrift site-packages
if(EXISTS "${CMAKE_INSTALL_PREFIX}/lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages")
  set(TEST_PYTHONPATH "${TEST_PYTHONPATH}:${CMAKE_INSTALL_PREFIX}/lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages")
endif()

#####
# Create fbthrift_test package to avoid module shadowing
#####
# Problem: Test files like binary.py, iobuf.py, transitive_deps.py have same names
# as gen-python packages (binary/, iobuf/, transitive_deps/).
# When running "python binary.py", Python adds the test directory to sys.path[0],
# causing "import binary" to find the test file instead of the package.
#
# Solution (same as Buck): Run tests as modules, not scripts.
# Create a fbthrift_test/ package with symlinks to test files, then run:
#   python -m unittest fbthrift_test.binary
# This sets sys.path[0] to '' (cwd), so "import binary" finds the package.
#####

set(_fbthrift_test_dir "${_gen_python}/fbthrift_test")

# Create fbthrift_test package directory
add_custom_command(
  OUTPUT "${_fbthrift_test_dir}/__init__.py"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_fbthrift_test_dir}"
  COMMAND ${CMAKE_COMMAND} -E touch "${_fbthrift_test_dir}/__init__.py"
  COMMENT "Creating fbthrift_test package directory"
)

# List of test files (excluding non-test files like testing_utils.py, test_server.py)
set(THRIFT_PYTHON_TEST_FILES
  abstract_types_flags_test.py
  adapter.py
  binary.py
  converter.py
  enums.py
  exceptions.py
  exceptions_ft.py
  iobuf.py
  intercompatibility.py
  lists.py
  maps.py
  metadata.py
  mutable_exceptions.py
  mutable_list_test.py
  mutable_map_test.py
  mutable_set_test.py
  mutable_structs.py
  mutable_structs_ft.py
  mutable_unions.py
  python_annotations_test.py
  refs.py
  serializer.py
  sets.py
  special_cases_test.py
  structs.py
  structs_ft.py
  test_helpers.py
  transitive_deps.py
  typeinfo_test.py
  unions.py
  unions_ft.py
)

# Also symlink helper files that tests import
set(THRIFT_PYTHON_TEST_HELPERS
  testing_utils.py
  test_server.py
)

# Create symlinks for all test files
set(TEST_SYMLINK_OUTPUTS "")
foreach(test_file ${THRIFT_PYTHON_TEST_FILES} ${THRIFT_PYTHON_TEST_HELPERS})
  set(_src "${CMAKE_CURRENT_SOURCE_DIR}/${test_file}")
  set(_dst "${_fbthrift_test_dir}/${test_file}")
  list(APPEND TEST_SYMLINK_OUTPUTS "${_dst}")
  add_custom_command(
    OUTPUT "${_dst}"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_dst}"
    DEPENDS "${_src}" "${_fbthrift_test_dir}/__init__.py"
    COMMENT "Symlinking ${test_file} to fbthrift_test package"
  )
endforeach()

# Add server/test .py file to fbthrift_test package
# This file is in python/server/test/ but needs to be accessible via fbthrift_test
set(_server_test_src "${CMAKE_CURRENT_SOURCE_DIR}/../server/test/python_async_processor_factory_test.py")
set(_server_test_dst "${_fbthrift_test_dir}/python_async_processor_factory_test.py")
add_custom_command(
  OUTPUT "${_server_test_dst}"
  COMMAND ${CMAKE_COMMAND} -E create_symlink "${_server_test_src}" "${_server_test_dst}"
  DEPENDS "${_server_test_src}" "${_fbthrift_test_dir}/__init__.py"
  COMMENT "Symlinking python_async_processor_factory_test.py to fbthrift_test package"
)
list(APPEND TEST_SYMLINK_OUTPUTS "${_server_test_dst}")

# Target to create all test symlinks
add_custom_target(thrift_python_test_package ALL
  DEPENDS "${_fbthrift_test_dir}/__init__.py" ${TEST_SYMLINK_OUTPUTS}
)

# Use DEPENDENCY_LIB_PATH from top-level CMakeLists.txt for LD_LIBRARY_PATH
# This contains all dependency library paths (glog, gflags, fmt, etc.)

# Register each test file with ctest
# Run as module to avoid sys.path[0] = test_dir shadowing
foreach(test_file ${THRIFT_PYTHON_TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_test(
    NAME thrift_python_${test_name}
    COMMAND ${Python3_EXECUTABLE} -m unittest fbthrift_test.${test_name} -v
    WORKING_DIRECTORY ${_gen_python}
  )
  set_tests_properties(thrift_python_${test_name} PROPERTIES
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
  )
endforeach()

#####
# thrift/test/thrift-python/ tests
#####
# These tests are in a separate directory and use namespace thrift.test.thrift_python
# The thrift_library entries already exist above (struct_test, union_test, enum_test, included)

set(THRIFT_TEST_THRIFT_PYTHON_DIR "${CMAKE_SOURCE_DIR}/thrift/test/thrift-python")

# Create thrift_test_thrift_python_tests package for these tests
set(_thrift_test_tests_dir "${_gen_python}/thrift_test_thrift_python_tests")

add_custom_command(
  OUTPUT "${_thrift_test_tests_dir}/__init__.py"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_thrift_test_tests_dir}"
  COMMAND ${CMAKE_COMMAND} -E touch "${_thrift_test_tests_dir}/__init__.py"
  COMMENT "Creating thrift_test_thrift_python_tests package directory"
)

# Test files from thrift/test/thrift-python/
set(THRIFT_TEST_THRIFT_PYTHON_TEST_FILES
  abstract_types_test.py
  enum_test.py
  schema_evolution_test.py
  struct_test.py
  union_test.py
)

# Create symlinks for thrift/test/thrift-python/ test files
set(THRIFT_TEST_SYMLINK_OUTPUTS "")
foreach(test_file ${THRIFT_TEST_THRIFT_PYTHON_TEST_FILES})
  set(_src "${THRIFT_TEST_THRIFT_PYTHON_DIR}/${test_file}")
  set(_dst "${_thrift_test_tests_dir}/${test_file}")
  list(APPEND THRIFT_TEST_SYMLINK_OUTPUTS "${_dst}")
  add_custom_command(
    OUTPUT "${_dst}"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_dst}"
    DEPENDS "${_src}" "${_thrift_test_tests_dir}/__init__.py"
    COMMENT "Symlinking ${test_file} to thrift_test_thrift_python_tests package"
  )
endforeach()

# Target to create all thrift/test/thrift-python/ test symlinks
add_custom_target(thrift_test_thrift_python_test_package ALL
  DEPENDS "${_thrift_test_tests_dir}/__init__.py" ${THRIFT_TEST_SYMLINK_OUTPUTS}
  struct_test-python-target union_test-python-target enum_test-python-target included-python-target
)

# Register thrift/test/thrift-python/ tests with ctest
foreach(test_file ${THRIFT_TEST_THRIFT_PYTHON_TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_test(
    NAME thrift_test_thrift_python_${test_name}
    COMMAND ${Python3_EXECUTABLE} -m unittest thrift_test_thrift_python_tests.${test_name} -v
    WORKING_DIRECTORY ${_gen_python}
  )
  set_tests_properties(thrift_test_thrift_python_${test_name} PROPERTIES
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
  )
endforeach()

#####
# thrift/lib/python/test/adapters/ tests
#####
set(ADAPTERS_TEST_FILES
  atoi_test.py
  datetime_test.py
)

foreach(test_file ${ADAPTERS_TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_test(
    NAME thrift_python_adapters_${test_name}
    COMMAND ${Python3_EXECUTABLE} -m unittest thrift.python.test.adapters.${test_name} -v
    WORKING_DIRECTORY ${_gen_python}
  )
  set_tests_properties(thrift_python_adapters_${test_name} PROPERTIES
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
  )
endforeach()

#####
# thrift/lib/python/test/request_context_extractor/ tests
#####
add_test(
  NAME thrift_python_request_context_extractor_test
  COMMAND ${Python3_EXECUTABLE} -m unittest thrift.python.test.request_context_extractor.request_context_extractor_test -v
  WORKING_DIRECTORY ${_gen_python}
)
set_tests_properties(thrift_python_request_context_extractor_test PROPERTIES
  ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
)

#####
# thrift/lib/python/server/test/ tests
# Note: The .py test file imports from thrift.python.test.python_async_processor_factory_test
# We symlink the .py to fbthrift_test/ and run via fbthrift_test module
#####
add_test(
  NAME thrift_python_server_python_async_processor_factory_test
  COMMAND ${Python3_EXECUTABLE} -m unittest fbthrift_test.python_async_processor_factory_test -v
  WORKING_DIRECTORY ${_gen_python}
)
set_tests_properties(thrift_python_server_python_async_processor_factory_test PROPERTIES
  ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
)

#####
# thrift/lib/python/client/test/ tests
#
# These tests require proxygen library (for http2_helper.pyx).
# The test_server.py imports http2_helper which depends on proxygen::httpserver.
#
# Dependencies:
# - proxygen (HTTPServerOptions) - added as fbthrift manifest dependency
# - http2_helper.pyx - added to setup.py Cython extensions
# - thrift.py3.server - for get_context, SocketAddress (built as part of py3 bindings)
#####

set(CLIENT_TEST_DIR "${CMAKE_SOURCE_DIR}/thrift/lib/python/client/test")

# Create fbthrift_client_test package for client tests (same approach as fbthrift_test)
set(_fbthrift_client_test_dir "${_gen_python}/fbthrift_client_test")

add_custom_command(
  OUTPUT "${_fbthrift_client_test_dir}/__init__.py"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_fbthrift_client_test_dir}"
  COMMAND ${CMAKE_COMMAND} -E touch "${_fbthrift_client_test_dir}/__init__.py"
  COMMENT "Creating fbthrift_client_test package directory"
)

# Client test files
set(CLIENT_TEST_FILES
  async_client_test.py
  sync_client_test.py
)

# Helper files needed by client tests
set(CLIENT_TEST_HELPERS
  test_server.py
)

# Create symlinks for client test files
set(CLIENT_TEST_SYMLINK_OUTPUTS "")
foreach(test_file ${CLIENT_TEST_FILES} ${CLIENT_TEST_HELPERS})
  set(_src "${CLIENT_TEST_DIR}/${test_file}")
  set(_dst "${_fbthrift_client_test_dir}/${test_file}")
  list(APPEND CLIENT_TEST_SYMLINK_OUTPUTS "${_dst}")
  add_custom_command(
    OUTPUT "${_dst}"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${_src}" "${_dst}"
    DEPENDS "${_src}" "${_fbthrift_client_test_dir}/__init__.py"
    COMMENT "Symlinking ${test_file} to fbthrift_client_test package"
  )
endforeach()

# Target to create all client test symlinks
add_custom_target(thrift_python_client_test_package ALL
  DEPENDS "${_fbthrift_client_test_dir}/__init__.py" ${CLIENT_TEST_SYMLINK_OUTPUTS}
  create_binding_symlink_thrift_python_client_test
  test-python-target leaf-python-target
)

# Register client tests with ctest
foreach(test_file ${CLIENT_TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_test(
    NAME thrift_python_client_${test_name}
    COMMAND ${Python3_EXECUTABLE} -m unittest fbthrift_client_test.${test_name} -v
    WORKING_DIRECTORY ${_gen_python}
  )
  set_tests_properties(thrift_python_client_${test_name} PROPERTIES
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH}"
  )
endforeach()
