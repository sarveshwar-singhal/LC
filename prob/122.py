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

    """
    to check if lists and other objects are passed by reference or not.
    """
    def modifyList(self, l1: List[int]) -> None:
        for i in range(len(l1)):
            l1[i] *= 2
        return

def main():
    l1 = [1, 2,3,4]
    print(l1)
    s1 = Solution()
    s1.modifyList(l1)
    print(l1)



if __name__ == "__main__":
    main()