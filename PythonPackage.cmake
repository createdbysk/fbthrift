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

# make_python_package
# Makes a directory into a Python package
#
# Params:
#   @target_name - The CMake target to attach this command to
#   @dir_path - The directory to make into a Python package
#
# EXPERIMENT: Testing if __init__.py creation is needed
# Modern Python 3.3+ supports implicit namespace packages
function(make_python_package target_name dir_path)
  # add_custom_command(
  #   TARGET ${target_name}
  #   POST_BUILD
  #   COMMAND ${CMAKE_COMMAND} -E touch "${dir_path}/__init__.py"
  # )
endfunction()
