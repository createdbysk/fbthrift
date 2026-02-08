# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

# pyre-unsafe

import unittest

from facebook.thrift.example.sum.sum.thrift_types import SumRequest, SumResponse
from handler import Handler


class TestSum(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.handler = Handler()

    async def test_sum_happy_path(self) -> None:
        request = SumRequest(num1=1, num2=2)
        response: SumResponse = await self.handler.sum(request)
        self.assertEqual(response.sum, 3)

    async def test_sum_unhappy_path(self) -> None:
        request = SumRequest(num1=10, num2=20)
        response: SumResponse = await self.handler.sum(request)
        self.assertNotEqual(response.sum, 20)
