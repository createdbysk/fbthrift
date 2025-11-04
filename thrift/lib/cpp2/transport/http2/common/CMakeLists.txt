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

# HTTP2 transport library for Thrift
# Based on BUCK definition in fbcode/thrift/lib/cpp2/transport/http2/common/BUCK

# Find proxygen using CONFIG mode to get properly namespaced targets
# This ensures INTERFACE_INCLUDE_DIRECTORIES propagate correctly
find_package(proxygen CONFIG REQUIRED)

add_library(
  http2_routing

  HTTP2RoutingHandler.cpp
  H2Channel.cpp
  SingleRpcChannel.cpp
)

target_include_directories(
  http2_routing
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(
  http2_routing
  PUBLIC
    thriftcpp2
    proxygen::proxygen           # Use namespaced target - propagates includes!
    proxygen::proxygenhttpserver # Use namespaced target - propagates includes!
    Folly::folly                 # Note: Capital F in Folly::folly
    ${GLOG_LIBRARIES}
)

# Install library
install(
  TARGETS http2_routing
  EXPORT fbthrift-exports
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

# Install headers
install(
  FILES
    HTTP2RoutingHandler.h
    H2Channel.h
    SingleRpcChannel.h
  DESTINATION include/thrift/lib/cpp2/transport/http2/common
)
