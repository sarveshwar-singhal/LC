from typing import List

"""
class to count the number of islands
"""
class Solution:

    """
    tc beats 53.64%, sc beats 79.45%
    """
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n, ans = len(grid), len(grid[0]), 0
        traverse = list(["0"] * n for _ in range(m))
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and traverse[i][j] == "0":
                    self.__map_island(grid, traverse, i, j)
                    ans +=1
        return ans

    def __map_island(self, grid: List[List[str]], traverse: List[List[str]], row, col):
        #base case
        if row >= len(grid) or col >= len(grid[0]) or row < 0 or col < 0 or traverse[row][col] == "1":
            return

        if grid[row][col] == "0":
            return

        #rec case
        traverse[row][col] = "1"
        self.__map_island(grid, traverse, row+1, col)
        self.__map_island(grid, traverse, row - 1, col)
        self.__map_island(grid, traverse, row, col+1)
        self.__map_island(grid, traverse, row, col-1)
        return


def main():
    s1 = Solution()
    grid = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]
    ]

    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]
    print(s1.numIslands(grid))



if __name__ == "__main__":
    main()