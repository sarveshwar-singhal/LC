from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
not working
"""
class Solution:

    """
    tle 52/58 passed. input size 5 * 10^4. It will known, it will throw TLE
    """
    def __traverse_len(self, root: Optional[TreeNode], dir, sz):
        #base case
        if root is None:
            return sz

        if not dir:
            return self.__traverse_len(root.right, not dir, sz + 1)
        else:
            return  self.__traverse_len(root.left, not dir, sz+ 1)


    def __traverse_tree(self, root: Optional[TreeNode]):
        if root is None:
            return

        #dir = false -> left, dir= true -> right
        self.__ans = max(self.__ans, self.__traverse_len(root.left, False, 0))
        self.__ans = max(self.__ans, self.__traverse_len(root.right, True, 0))
        self.__traverse_tree(root.left)
        self.__traverse_tree(root.right)

        return

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        self.__ans = 0
        self.__traverse_tree(root)
        return self.__ans


"""
throws tle, 53/58 tc passed. needs to improved.
"""
class Solution1:

    def __traverse_len(self, root: Optional[TreeNode], dir, sz):
        tmp = root
        while tmp is not None:
            sz += 1
            if not dir:
                tmp = tmp.left
            else:
                tmp = tmp.right
            dir = not dir
        return sz-1


    def __traverse_tree(self, root: Optional[TreeNode]):
        if root is None:
            return

        #dir = false -> left, dir= true -> right
        self.__ans = max(self.__ans, self.__traverse_len(root, False, 0))
        self.__ans = max(self.__ans, self.__traverse_len(root, True, 0))
        self.__traverse_tree(root.left)
        self.__traverse_tree(root.right)

        return

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.__ans = 0
        self.__traverse_tree(root)
        return self.__ans


"""
this works for zig zag tree traversal
"""
class Solution2:

    def __traverse_tree(self, root: Optional[TreeNode], dir, sz):
        if root is None:
            return

        self.__ans = max(self.__ans, sz)
        if dir:
            self.__traverse_tree(root.right, not dir, sz + 1)
            self.__traverse_tree(root.left, dir, 1)
        else:
            self.__traverse_tree(root.left, not dir, sz+1)
            self.__traverse_tree(root.right, dir, 1)

        return

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.__ans = 0
        #dir = false -> left, dir = true -> right
        self.__traverse_tree(root, True, 0)
        self.__traverse_tree(root, False, 0)
        return self.__ans

