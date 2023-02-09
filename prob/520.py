class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() or word.islower() or word.capitalize() == word:
            return True
        return False


def main():
    word = "leetcode"
    word = "Leetcode"
    word = "LeetCode"
    s1 = Solution()
    print(s1.detectCapitalUse(word))

if __name__ == '__main__':
    main()