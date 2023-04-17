from typing import List
from collections import deque
class Solution:

    """
    not worked, logic not correct
    """
    def validateStackSequences1(self, pushed: List[int], popped: List[int]) -> bool:
        stack = deque()
        j=0
        for i in range(len(pushed)):
            if pushed[i] == popped[j]:
                j+=1
            else:
                # stack.append()
                while stack.__len__() > 0:
                    x = stack.pop()
                    if x != popped[j]:
                        stack.append(x)
                        break
                    j+=1
                stack.append(pushed[i])
        return stack.__sizeof__() > 0

    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = deque()
        j=0
        for i in range(len(pushed)):
            stack.append(pushed[i])
            while stack.__len__() > 0:
                x = stack.pop()
                if x != popped[j]:
                    stack.append(x)
                    break
                j+=1
        return stack.__len__() == 0


def main():
    s1 = Solution()
    pushed = [1, 2, 3, 4, 5]
    popped = [4,5,3,2,1]
    print(s1.validateStackSequences(pushed, popped))
    return


if __name__ == "__main__":
    main()