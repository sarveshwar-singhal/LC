class Solution:
    """
    in progress
    """
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        sign = "+"
        for i in range(len(s)):
            if s[i] == '+' or s[i] == '-':
                sign = s[i]
                break
        return 0
