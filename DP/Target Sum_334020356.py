class Solution(object):
    def findTargetSumWays(self, nums, S):
        
        def subset_sum_count(nums, n, w):
            dp = [[0] * (w+1) for _ in range(n+1)]
            
            dp[0][0] = 1
            
            for i in range(1, n+1):
                for j in range(0, w+1):
                    if nums[i-1] <= j:
                        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j]
                    else:
                        dp[i][j] = dp[i-1][j]
            return dp
        
        total = sum(nums)
        if S > total:
            return 0
        if (S + total) % 2 != 0:
            return 0
        
        w = (S + total) // 2
        n = len(nums)
        dp = subset_sum_count(nums, n, w)
        return dp[n][w]
