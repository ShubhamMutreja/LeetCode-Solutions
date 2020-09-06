class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j]<0:
                    res += 1
        return res
