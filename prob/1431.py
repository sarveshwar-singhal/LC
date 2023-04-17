from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        ans = [True] * len(candies)
        for i in range(len(candies)):
            if candies[i] + extraCandies < mx:
                ans[i] = False
        return ans