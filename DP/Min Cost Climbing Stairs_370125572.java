class Solution {
    public int memo(int[] cost,int i,int n,int[] dp) {
        if(i==n)
            return dp[i]=cost[i];
        if(i>n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = Math.min(memo(cost,i+1,n,dp), memo(cost,i+2,n,dp)) + cost[i];
    }
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length -1;
        int[] dp = new int[n+1];
        
        for (int i = 0; i < dp.length; i++) {
                dp[i] = -1;
        }
        return Math.min(memo(cost,0,n,dp),memo(cost,1,n,dp));
    }
}
