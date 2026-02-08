// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

// You will need to change this package to something unique if creating a copy
package "facebook.com/thrift/example/sum"

namespace cpp2 facebook.thrift.example.sum
// This must match the py3_namespace in the TARGETS file.
namespace py3 facebook.thrift.example.sum

struct SumRequest {
  1: i32 num1;
  2: i32 num2;
}

struct SumResponse {
  1: i32 sum;
}

service SumService {
  SumResponse sum(1: SumRequest request);
}
