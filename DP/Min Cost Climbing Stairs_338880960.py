dp = [0]*1001
def fun(cost,s,n):
    if s>=n:
        return 0
    if dp[s] != -1:
        return dp[s]
    dp[s] = min(cost[s] + fun(cost,s+1,n),cost[s]+fun(cost,s+2,n))
    return dp[s]
    
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        for i in range(n+1):
            dp[i] = -1
        return min(fun(cost,0,n),fun(cost,1,n))
        
