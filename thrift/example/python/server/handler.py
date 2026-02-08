# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

# pyre-unsafe

from facebook.thrift.example.sum.sum.thrift_services import SumServiceInterface
from facebook.thrift.example.sum.sum.thrift_types import SumRequest, SumResponse


class Handler(SumServiceInterface):
    async def sum(self, request: SumRequest) -> SumResponse:
        return SumResponse(sum=request.num1 + request.num2)
