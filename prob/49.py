from typing import List
from collections import Counter

class Solution:

    """
    will not work, didn't think through the logic
    """
    def groupAnagrams1(self, strs: List[str]) -> List[List[str]]:
        match = [0] * 101
        for word in strs:
            n = len(word)
            if match[n] == 0:
                match[n] = dict()
            set1 = set(word)
            if set1 not in match[n]:
                match[n][set1] = []
            match[n][set1].append(word)
        return [[""]]

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        for i in range(len(strs)):
            strs[i] = "".join(sorted(strs[i]))
        strs.sort()
        ans = []
        prev = Counter()
        # for i in range(len(strs)):
        #     a
        for word in strs:
            # print(word)
            tmp = Counter(word)
            if tmp != prev:
                ans.append([word])
                prev = tmp
            else:
                ans[-1].append(word)
        return ans


def main():
    s1 = Solution()
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    ans = s1.groupAnagrams(strs)
    print(ans)
    return


if __name__ == "__main__":
    main()
