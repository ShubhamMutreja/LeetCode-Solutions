class Solution {
    public int memo(int n,int[] dp) {
        if(n==0)
            return dp[n]=1;
        if(n<0)
            return 0;
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    public int climbStairs(int n)
    {
        int[] dp = new int[n+1];
        //return memo(n,dp);
        for (int i = 0; i < dp.length; i++) {
                dp[i] = -1;
        }
        for(int i=0;i<=n;i++)
        {
            if(i==0)
            {
                dp[i] = 1;
                continue;
            }
            if(dp[i] != -1)
                continue;
            int step=0;
            if(i-1 >= 0)
                step += dp[i-1];
            if(i-2 >= 0)
                step += dp[i-2];
            
            dp[i] = step;
            
                
        }
        return dp[n];
    }
}
