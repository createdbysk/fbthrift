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

# Verify thrift-python generated types are importable and functional.
#
# thrift_library() should produce a sum-python target, just as it produces
# chatroom-cpp2 for C++. We depend on that target to ensure code generation
# runs before the test.

find_package(Python3 REQUIRED COMPONENTS Interpreter)

add_test(
  NAME thrift_python_sum_types_example
  COMMAND
    Python3::Interpreter "${CMAKE_CURRENT_SOURCE_DIR}/sum_types_example.py"
)

set_tests_properties(
  thrift_python_sum_types_example
  PROPERTIES
    ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}/../if/gen-python"
    FIXTURES_REQUIRED sum_python_codegen
)

# This is the key: depend on the sum-python target from thrift_library().
# If thrift_library() doesn't create this target for python, this fails.
add_custom_target(sum_python_codegen_fixture ALL)
add_dependencies(sum_python_codegen_fixture sum-python)
set_tests_properties(
  thrift_python_sum_types_example
  PROPERTIES
    FIXTURES_REQUIRED sum_python_codegen
)
