#!/usr/bin/env python3
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

"""
Validate thrift-python generated types from sum.thrift.

Run after building with thrift_library(..., "python", ...) to verify
that the generated Python modules are importable and functional.

Usage:
    PYTHONPATH=<build_output>/gen-python python3 sum_types_example.py
"""

import sys

from example.sum.thrift_types import SumRequest, SumResponse


def main():
    # Create a SumRequest and verify field access
    request = SumRequest(num1=3, num2=7)
    assert request.num1 == 3, f"Expected num1=3, got {request.num1}"
    assert request.num2 == 7, f"Expected num2=7, got {request.num2}"

    # Create a SumResponse and verify field access
    response = SumResponse(sum=10)
    assert response.sum == 10, f"Expected sum=10, got {response.sum}"

    print("All thrift-python type checks passed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
