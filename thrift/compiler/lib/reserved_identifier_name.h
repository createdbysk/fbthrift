/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>
#include <boost/algorithm/string.hpp>

namespace apache::thrift::compiler {

inline bool is_reserved_identifier_name(std::string_view name) {
  static const std::string prefix = "fbthrift";
  static const std::locale utf8_locale("en_US.UTF-8");

  auto pos = name.find_first_not_of("_");
  if (pos == std::string_view::npos) {
    return false;
  }

  // For backwards compatibility with older C++ versions,
  // use the string_view constructor that accepts a
  // const char *const and size_t.
  auto after_underscores =
      std::string_view(name.data() + pos, name.end() - name.begin() - pos);

  return boost::algorithm::istarts_with(after_underscores, prefix, utf8_locale);
}

} // namespace apache::thrift::compiler
