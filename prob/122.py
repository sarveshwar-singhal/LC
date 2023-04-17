from typing import List

class Solution:

    """
    buy sell stock II
    tc beats 99.1%, 50 ms, sc beats 18.41% 15.2 MB
    """
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        n = len(prices)
        for i in range(n-1):
            if prices[i] < prices[i+1]:
                ans += prices[i+1] - prices[i]
        return ans