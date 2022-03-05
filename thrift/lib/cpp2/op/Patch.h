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

#include <thrift/lib/cpp2/op/detail/Patch.h>
#include <thrift/lib/cpp2/type/Tag.h>
#include <thrift/lib/thrift/gen-cpp2/patch_types.h>

namespace apache {
namespace thrift {
namespace op {

namespace detail {
BoolPatch<BoolPatchStruct> patchType(type::bool_t);
NumberPatch<BytePatchStruct> patchType(type::byte_t);
NumberPatch<I16PatchStruct> patchType(type::i16_t);
NumberPatch<I32PatchStruct> patchType(type::i32_t);
NumberPatch<I64PatchStruct> patchType(type::i64_t);
NumberPatch<FloatPatchStruct> patchType(type::float_t);
NumberPatch<DoublePatchStruct> patchType(type::double_t);
StringPatch<StringPatchStruct> patchType(type::string_t);
AssignPatch<BinaryPatchStruct> patchType(type::binary_t);
} // namespace detail

// The patch represenations for the base thrift types.
//
// All patch types support the following methods:
// - empty() - Returns true iff the patch is a noop.
// - clear() - Makes the patch empty.
// - apply(T&& value) - Applies the patch to the given value, in place.
// - merge(P&& next) - Merges the 'next' patch into this one, such that the
// result is equivalent to applying this and next in sequence.
// - assign(U&& value) - Updates the patch to assign the given value.
// - operator=(U&& value) - An alias for assign.
// - get() - Returns the underlying Thrift representation for the patch.
//
// For example:
//  int32_t value = 1;
//  I32Patch patch;
//  patch = 2;          // Equivalent to calling patch.assign(2).
//  patch.apply(value); // Sets value to 2;
template <typename Tag>
using patch_type = decltype(detail::patchType(Tag{}));

// A patch for a boolean, which additionally supports:
// - invert() - Inverts the patch, in place.
// - operator!(BoolPatch) - Returns an inverted version of the given patch.
using BoolPatch = patch_type<type::bool_t>;

// Patches for number types, which additionally support:
// - add(T value) - Update to the patch to additionally add the given value.
// - subtract(T value) - Update to the patch to additionally subtract the given
// value.
// - operators -, -=, +, += - Alias to the appropriate add and subtract calls.
using BytePatch = patch_type<type::byte_t>;
using I16Patch = patch_type<type::i16_t>;
using I32Patch = patch_type<type::i32_t>;
using I64Patch = patch_type<type::i64_t>;
using FloatPatch = patch_type<type::float_t>;
using DoublePatch = patch_type<type::double_t>;

// A patch for a string, which additionally supports:
// - append(...) - Updates the patch to additionally append the given value.
// - prepend(U&&) - Updates the patch to additionally prepend the given value.
// - operators +, += - Alias to the appropriate append and prepend calls.
using StringPatch = patch_type<type::string_t>;

// TODO (afuller): Add more binary patch operations.
using BinaryPatch = patch_type<type::binary_t>;

} // namespace op
} // namespace thrift
} // namespace apache
