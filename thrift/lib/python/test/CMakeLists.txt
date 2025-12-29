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

# Include ThriftLibrary macros (for standalone builds, CMAKE_MODULE_PATH must be set)
include(ThriftLibrary OPTIONAL)

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

# convertible.thrift - py-deprecated (generates ttypes.py for converter.py test)
thrift_library(
  "convertible"
  ""
  "py"
  ""
  "${PY3_TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE ""
  TARGET_NAME_BASE "convertible_py_deprecated"
)

# NOTE: convertible.thrift py3 generator is NOT supported by thrift_library.
# The py3 generator creates Cython code requiring separate compilation.
# converter.py test is BLOCKED until py3/Cython support is added.

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

# testing.thrift has namespace py3 "" (empty) - uses filename as package
thrift_library(
  "testing"
  "TestingService;TestingServiceChild;ExtendServiceWithNoTypes;ClientMetadataTestingService"
  "python"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
)

# Files with namespace py3 "testing" - output to testing/<filename>/
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

# py_deprecated_asyncio_test.thrift - py-deprecated (generates ttypes.py for converter.py test)
# namespace py.asyncio testing.py_deprecated_asyncio_test
thrift_library(
  "py_deprecated_asyncio_test"
  ""
  "py"
  "asyncio"
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing.py_deprecated_asyncio_test"
  TARGET_NAME_BASE "py_deprecated_asyncio_test_py"
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

# py_deprecated_asyncio_fallback_test.thrift - py-deprecated (generates ttypes.py for converter.py test)
# namespace py testing.py_deprecated_asyncio_fallback_test
thrift_library(
  "py_deprecated_asyncio_fallback_test"
  ""
  "py"
  ""
  "${TEST_THRIFT_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  ""
  THRIFT_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
  NAMESPACE "testing.py_deprecated_asyncio_fallback_test"
  TARGET_NAME_BASE "py_deprecated_asyncio_fallback_test_py"
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
# Note: Cython/setuptools uses "lib.linux-<arch>-cpython-<version>" format (e.g., lib.linux-x86_64-cpython-310)
set(_cybld_base "${CMAKE_BINARY_DIR}/thrift/lib/cybld")
set(_cybld "${_cybld_base}/build/lib.linux-${CMAKE_HOST_SYSTEM_PROCESSOR}-cpython-${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}")
set(_gen_python "${CMAKE_CURRENT_BINARY_DIR}/gen-python")
set(_gen_py "${CMAKE_CURRENT_BINARY_DIR}/gen-py")

# Helper function: create symlink from gen-python to cybld
function(add_test_namespace_symlink name source_path target_path)
  # Get the parent directory of the symlink target
  get_filename_component(target_parent_dir "${target_path}" DIRECTORY)

  add_custom_target(create_binding_symlink_${name} ALL
    DEPENDS ${ARGN} thrift_python_and_py3_bindings
  )
  add_custom_command(
    TARGET create_binding_symlink_${name}
    PRE_BUILD
    # First create the parent directory if it doesn't exist
    COMMAND ${CMAKE_COMMAND} -E make_directory "${target_parent_dir}"
    # Then create the symlink
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${source_path}" "${target_path}"
  )
endfunction()

# Helper function: create multiple symlinks for one target
function(add_test_namespace_symlinks name)
  add_custom_target(create_binding_symlink_${name} ALL
    DEPENDS ${ARGN} thrift_python_and_py3_bindings
  )
endfunction()

function(add_symlink_command target_name source_path target_path)
  # Get the parent directory of the symlink target
  get_filename_component(target_parent_dir "${target_path}" DIRECTORY)

  add_custom_command(
    TARGET create_binding_symlink_${target_name}
    PRE_BUILD
    # First create the parent directory if it doesn't exist
    COMMAND ${CMAKE_COMMAND} -E make_directory "${target_parent_dir}"
    # Then create the symlink
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
# Create the target directory first
add_custom_command(
  TARGET create_binding_symlink_thrift_python_client_test
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_cybld}/thrift/python/test"
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
# Note: metadata is in _cybld_base (cybld/), not _cybld (cybld/build/lib.../)
add_custom_target(apache_thrift_metadata_symlink ALL
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_cybld_base}/apache/thrift/metadata"
    "${_gen_python}/apache/thrift/metadata"
  DEPENDS terse_write-python-target
  COMMENT "Creating symlink for apache.thrift.metadata"
)

# 11. Symlink py-deprecated files from gen-py to gen-python for converter.py test
# Problem: gen-python/convertible/ shadows gen-py/convertible/ in PYTHONPATH
# Solution: symlink ttypes.py and constants.py into gen-python/convertible/
add_custom_target(convertible_py_deprecated_symlink ALL
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_gen_py}/convertible/ttypes.py"
    "${_gen_python}/convertible/ttypes.py"
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_gen_py}/convertible/constants.py"
    "${_gen_python}/convertible/constants.py"
  DEPENDS convertible_py_deprecated-py-target convertible-python-target
  COMMENT "Creating symlinks for py-deprecated files in gen-python/convertible/"
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

# py-deprecated testing namespace package (for gen-py/testing/)
# Required for imports like testing.py_deprecated_asyncio_test.ttypes
add_custom_target(python_package_testing_py_deprecated ALL
  DEPENDS py_deprecated_asyncio_test_py-py-target py_deprecated_asyncio_fallback_test_py-py-target
)
add_custom_command(
  TARGET python_package_testing_py_deprecated
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_gen_py}/testing"
  COMMAND ${CMAKE_COMMAND} -E touch "${_gen_py}/testing/__init__.py"
  COMMENT "Creating gen-py/testing/__init__.py for py-deprecated imports"
)

#####
# Python Test Definitions
#####

# ==========================================================================
# WHEEL-BASED TEST SETUP
# ==========================================================================
# Instead of complex PYTHONPATH + symlinks, we install wheels:
# 1. thrift wheel - provides thrift.python.*, thrift.py3.*, thrift.lib.python.*
# 2. folly wheel - assumed already installed by getdeps (provides folly.iobuf, etc.)
#
# TEST_PYTHONPATH only needs:
# - _gen_python: generated test thrift code (testing.thrift_types, etc.)
# - _gen_py: py-deprecated generated code
# - _thrift_py: py-deprecated runtime (thrift.Thrift, thrift.transport, etc.)
# ==========================================================================

# Install thrift wheel before running tests
# The wheel is built by thrift_python_and_py3_bindings target in thrift/lib/CMakeLists.txt
# Use CMAKE_BINARY_DIR (top-level build dir) for absolute path to avoid fragile relative paths
# Use --target to install to a known directory that we add to TEST_PYTHONPATH
set(_thrift_wheel_dir "${CMAKE_BINARY_DIR}/thrift/lib/cybld/dist")
set(_thrift_wheel_install_dir "${CMAKE_BINARY_DIR}/thrift/lib/thrift_wheel_pythonpath")
set(_wheel_suffix "cp${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}-cp${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}-linux_${CMAKE_HOST_SYSTEM_PROCESSOR}")
add_custom_target(install_thrift_wheel ALL
  DEPENDS thrift_python_and_py3_bindings
  COMMAND ${Python3_EXECUTABLE} -m pip install --force-reinstall --no-deps
    --target "${_thrift_wheel_install_dir}"
    "${_thrift_wheel_dir}/thrift-0.0.1-${_wheel_suffix}.whl"
  COMMENT "Installing thrift wheel for tests"
)

# Folly Python bindings are pre-installed by getdeps into FOLLY_PYTHON_SITE_PACKAGES
# (located at installed/folly/local/lib/python3.10/dist-packages/)
# We add this to PYTHONPATH below - no need to pip install a wheel.
if(NOT DEFINED FOLLY_PYTHON_SITE_PACKAGES OR NOT EXISTS "${FOLLY_PYTHON_SITE_PACKAGES}")
  message(FATAL_ERROR "FOLLY_PYTHON_SITE_PACKAGES not found: ${FOLLY_PYTHON_SITE_PACKAGES}. "
    "Ensure folly is built with Python bindings before building fbthrift tests.")
endif()
message(STATUS "Adding FOLLY_PYTHON_SITE_PACKAGES to TEST_PYTHONPATH: ${FOLLY_PYTHON_SITE_PACKAGES}")

# Build PYTHONPATH for tests
# With wheel-based approach for thrift, we need paths for:
# - Thrift wheel install directory (thrift.python.*, thrift.py3.*, etc.)
# - Generated test thrift code (testing.thrift_types, etc.)
# - py-deprecated runtime and generated code
# - Folly Python bindings (pre-installed by getdeps)
set(_thrift_py "${CMAKE_INSTALL_PREFIX}/lib/fb-py-libs/thrift_py")
set(TEST_PYTHONPATH "${_thrift_wheel_install_dir}:${_gen_python}:${_gen_py}:${FOLLY_PYTHON_SITE_PACKAGES}")

# Symlink thrift.util from thrift_py INTO the wheel directory
# Problem: py-deprecated imports like `from thrift.util.Recursive import ...` fail
# because the thrift wheel doesn't include thrift.util (it's a py-deprecated module)
# Solution: symlink thrift_py/thrift/* into the wheel's thrift/ directory
# This way py-deprecated modules are found when Python imports from the wheel's thrift package
#
# IMPORTANT: Do NOT create gen-python/thrift/__init__.py - that would shadow
# the wheel's thrift package, breaking imports like thrift.python.abstract_types
add_custom_target(thrift_py_deprecated_symlinks ALL
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_thrift_py}/thrift/util"
    "${_thrift_wheel_install_dir}/thrift/util"
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_thrift_py}/thrift/Thrift.py"
    "${_thrift_wheel_install_dir}/thrift/Thrift.py"
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_thrift_py}/thrift/protocol"
    "${_thrift_wheel_install_dir}/thrift/protocol"
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${_thrift_py}/thrift/transport"
    "${_thrift_wheel_install_dir}/thrift/transport"
  COMMENT "Creating symlinks for py-deprecated modules in wheel directory"
  DEPENDS install_thrift_wheel
)

# ==========================================================================
# SYMLINKS NO LONGER NEEDED - WHEEL APPROACH
# ==========================================================================
# The following symlink targets have been replaced by wheel-based approach:
# - thrift_lib_symlinks
# - thrift_py3_symlinks
# - thrift_python_runtime_symlinks
# - CMAKE_INSTALL_PREFIX site-packages addition to TEST_PYTHONPATH
#
# The thrift wheel (installed by install_thrift_wheel target above) provides:
# - thrift.python.*
# - thrift.py3.*
# - thrift.lib.python.*
# - apache.thrift.metadata
#
# Folly Python bindings are provided via FOLLY_PYTHON_SITE_PACKAGES in PYTHONPATH
# (pre-installed by getdeps into installed/folly/local/lib/python3.10/dist-packages/)
# ==========================================================================

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
  # abstract_types_flags_test.py - SKIPPED: test expects abstract types flag to be disabled, but OSS build enables it
  adapter.py
  binary.py
  client_server.py
  # converter.py - SKIPPED: requires convertible.types from py3 codegen (not built)
  enums.py
  exceptions.py
  exceptions_ft.py
  iobuf.py
  # intercompatibility.py - SKIPPED: requires testing.types from py3 codegen (not built)
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

# Add dependency on py-deprecated symlinks for converter test
add_dependencies(thrift_python_test_package convertible_py_deprecated_symlink)

# Add dependency on thrift.util symlink to fix namespace shadowing
add_dependencies(thrift_python_test_package thrift_py_deprecated_symlinks)

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
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
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
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
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
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
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
  ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
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
  ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
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
# SKIPPED: async_client_test.py and sync_client_test.py require http2_helper.pyx
# which has undefined symbol: apache::thrift::HTTP2RoutingHandler
# The HTTP2RoutingHandler is not linked correctly in the OSS build.
# To fix: Need to link http2_helper extension against the library containing HTTP2RoutingHandler
set(CLIENT_TEST_FILES
  # async_client_test.py  - SKIPPED: requires http2_helper (HTTP2RoutingHandler linking issue)
  # sync_client_test.py   - SKIPPED: requires http2_helper (HTTP2RoutingHandler linking issue)
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
    ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
  )
endforeach()

#####
# thrift/lib/python/test/metadata_response/ tests
#
# Tests for metadata response handling.
# Requires:
# - metadata_response.pyx Cython extension (added to setup.py)
# - thrift.lib.python.test.test_server helper
# - testing.thrift_services and testing.thrift_types (generated)
# - apache.thrift.metadata.thrift_types (generated)
#####
add_test(
  NAME thrift_python_metadata_response_test
  COMMAND ${Python3_EXECUTABLE} -m unittest thrift.lib.python.test.metadata_response.metadata_response_test -v
  WORKING_DIRECTORY ${_gen_python}
)
set_tests_properties(thrift_python_metadata_response_test PROPERTIES
  ENVIRONMENT "PYTHONPATH=${TEST_PYTHONPATH};LD_LIBRARY_PATH=${DEPENDENCY_LIB_PATH};LD_PRELOAD=${FOLLY_LIB_DIR}/libfolly_python_cpp.so"
)
