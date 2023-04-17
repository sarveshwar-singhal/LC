from typing import List

class Solution:
    """
    will throw TLE as len(input) = pow(10, 5)
    """
    def maxProfit1(self, prices: List[int]) -> int:
        ans = 0
        n = len(prices)
        for i in range(n-1):
            temp_ans = float("-inf")
            buy = prices[i]
            for j in range(i+1, n):
                temp_ans = max(temp_ans, prices[j] - buy)
            ans = max(ans, temp_ans)
        return ans

    """
    works, tc beats only 5.1%, sc beats 98.8%. Still can be improved
    """
    def maxProfit2(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        buy = [0] * n
        sell = [0] * n
        buy[0] = prices[0]
        sell[-1] = prices[-1]
        for i in range(1, n):
            buy[i] = min(buy[i-1], prices[i])
            sell[n-i-1] = max(sell[n-i], prices[n-i-1])
        for i in range(n):
            ans = max(ans, sell[i] - buy[i])
        return ans

    """
    now tc beats 22.85%, sc beats 29.39%"""
    def maxProfit3(self, prices: List[int]) -> int:
        ans = 0
        mn = float("inf")
        for i in range(len(prices)):
            mn = min(mn, prices[i])
            mx = prices[i]
            ans = max(ans, mx-mn)
        return ans

    """
    tc beats 53.74% sc beats 29.39%
    """
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        mn = 100_000
        for i in range(len(prices)):
            mn = min(mn, prices[i])
            mx = prices[i]
            if mx - mn > ans:
                ans = mx - mn
            # ans = max(ans, mx-mn)
        return ans