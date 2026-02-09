# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

# pyre-unsafe

from example.sum.thrift_services import SumServiceInterface
from example.sum.thrift_types import SumRequest, SumResponse


class Handler(SumServiceInterface):
    async def sum(self, request: SumRequest) -> SumResponse:
        return SumResponse(sum=request.num1 + request.num2)
