class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}
        for alpha in s:
            if alpha in freq:
                freq[alpha] += 1
            else:
                freq[alpha] = 1
        li = sorted(freq, key=freq.get, reverse=True)
        # li.sort(key=lambda x: x[1], reverse=True)
        # print(li)
        ans = ""
        for alpha in li:
            ans += alpha * freq[alpha]
        # for [alpha, fr] in li:
        #     ans += alpha*fr
        return ans


def main():
    s1 = Solution()
    word = "tree"
    ans = s1.frequencySort(word)
    print(ans)
    return


if __name__ == '__main__':
    main()