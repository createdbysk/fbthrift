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
