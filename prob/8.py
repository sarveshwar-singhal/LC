class Solution:
    """
    wrong
    """
    def myAtoi1(self, s: str) -> int:
        s = s.strip()
        sign = "+"
        for i in range(len(s)):
            if s[i] == '+' or s[i] == '-':
                sign = s[i]
                break
            if ord(s[i]) >= 48 and ord(s[i]) < 58:
                i -= 1
                break
        num = ""
        i += 1
        while i < len(s) and ord(s[i]) < 58:
            num += s[i]
            i += 1
        if len(num) < 1:
            return 0
        num = sign + num
        return int(num)

    def myAtoi(self, s: str) -> int:
        s = s.strip()
        ans = 0
        if len(s) > 0:
            if s[0] != "+" and s[0] != "-" and not (ord(s[0]) >= 48 and ord(s[0]) <= 57):
                return 0
            sign = "-" if s[0] == '-' else '+'
            i = 1 if s[0] == '-' or s[0] == '+' else 0
            num = ""
            while i < len(s) and ord(s[i]) >= 48 and ord(s[i]) <= 57:
                num += s[i]
                i += 1
            if len(num) < 1:
                return 0
            num = sign + num
            ans = int(num)
            if ans < -2147483648:
                ans = -2147483648
            if ans > 2147483647:
                ans = 2147483647
        return ans