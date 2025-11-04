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

PROJECT(ThriftTransport_CPP2_Example CXX)

# Find all dependencies using correct patterns for Meta OSS libraries
# All of these use CONFIG mode and provide namespaced targets
find_package(folly CONFIG REQUIRED)   # Provides Folly::folly (capital F!)
find_package(wangle CONFIG REQUIRED)  # Provides wangle::wangle
find_package(fizz CONFIG REQUIRED)    # Provides fizz::fizz
find_package(proxygen CONFIG REQUIRED) # Provides proxygen::proxygen, proxygen::proxygenhttpserver
find_package(Glog REQUIRED)           # Provides glog::glog (MODULE mode)
find_package(range-v3 REQUIRED)       # Header-only, provides range-v3::range-v3

# gflags has compatibility layer - try CONFIG first, fallback to MODULE
find_package(gflags CONFIG QUIET)
if (gflags_FOUND)
  if (TARGET gflags-shared)
    set(GFLAGS_TARGET gflags-shared)
  elseif (TARGET gflags)
    set(GFLAGS_TARGET gflags)
  endif()
else()
  find_package(Gflags REQUIRED MODULE)
  set(GFLAGS_TARGET ${LIBGFLAGS_LIBRARY})
endif()

add_executable(
  example_server

  server/EchoService.h
  server/EchoService.cpp
  server/ChatRoomService.h
  server/ChatRoomService.cpp
  server/ExampleServer.cpp
)
target_link_libraries(
  example_server
  PRIVATE
    thriftcpp2
    chatroom-cpp2
    http2_routing
    Folly::folly                 # Capital F!
    wangle::wangle
    fizz::fizz
    proxygen::proxygen           # Use namespaced targets
    proxygen::proxygenhttpserver
    glog::glog
    ${GFLAGS_TARGET}
    range-v3::range-v3          # For MetadataExample.cpp includes
)
install(
  TARGETS example_server
  RUNTIME DESTINATION bin/cpp2/
)

add_executable(
  chatroom_client

  client/ChatRoomClient.cpp
)
target_link_libraries(
  chatroom_client

  chatroom-cpp2
)
install(
  TARGETS chatroom_client
  RUNTIME DESTINATION bin/cpp2/
)

add_executable(
  echo_client

  client/EchoClient.cpp
)
target_link_libraries(
  echo_client

  chatroom-cpp2
)
install(
  TARGETS echo_client
  RUNTIME DESTINATION bin/cpp2/
)
