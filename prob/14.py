from typing import List

class Solution:
    """
    tc beats 57.42% only, sc beats 36.31%
    """
    def longestCommonPrefix1(self, strs: List[str]) -> str:
        n = min(map(len, strs))
        prev = ""
        for i in range(n):
            tmp = prev + strs[0][i]
            for word in strs:
                if not word.startswith(tmp):
                    return prev
            prev = tmp
        return prev

    def longestCommonPrefix2(self, strs: List[str]) -> str:
        n = len(strs[0])
        for i in range(len(strs)):
            n = min(n, len(strs[i]))
        ans = ""
        for i in range(n):
            tmp = strs[0][i]
            for j in range(1, len(strs)):
                if strs[j][i] != tmp:
                    return ans
            ans += tmp
        return ans

    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs[0])
        for i in range(1, len(strs)):
            if len(strs[i]) < n:
                n = len(strs[i])
        ans = ""
        for i in range(n):
            tmp = strs[0][i]
            for j in range(1, len(strs)):
                if strs[j][i] != tmp:
                    return ans
            ans = ans + tmp
        return ans



def main():
    s1 = Solution()
    strs = ["flower","flow","flight"]
    print(s1.longestCommonPrefix(strs))


if __name__ == "__main__":
    main()