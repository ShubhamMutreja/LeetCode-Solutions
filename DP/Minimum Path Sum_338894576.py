import sys

def solve(arr,m,n,dp):
    if m < 0 or n<0:
        return sys.maxsize
    if m==0 and n==0:
        return arr[0][0]
    if dp[m][n] != -1:
        return dp[m][n]
    dp[m][n] = min(solve(arr,m-1,n,dp),solve(arr,m,n-1,dp)) + arr[m][n]
    return dp[m][n]
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[-1 for i in range(n+1)] for j in range(m+1)]
        return solve(grid,m-1,n-1,dp)
