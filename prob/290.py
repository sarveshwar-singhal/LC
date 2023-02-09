class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split(" ")
        if len(pattern) != len(s):
            return False
        patt = {}
        occur = {}
        for i, alpha in enumerate(pattern):
            if alpha in patt:
                if patt[alpha] != s[i]:
                    return False
            else:
                if s[i] not in occur:
                    patt[alpha] = s[i]
                    occur[s[i]] = 1
                else:
                    return False
        return True


def main():
    pattern = "abbc"
    s = "dog cat cat dog"
    s1 = Solution()
    print(s1.wordPattern(pattern, s))

if __name__ == '__main__':
    main()