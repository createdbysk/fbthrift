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

# Generate thrift code (cpp2 and thrift-python) from interface definitions
add_subdirectory(if)

# cpp2 examples are disabled by default due to build compatibility issues
option(thrift_build_examples_cpp2
  "Build C++ thrift examples"
  OFF
)
if(thrift_build_examples_cpp2)
  add_subdirectory(cpp2)
endif()
