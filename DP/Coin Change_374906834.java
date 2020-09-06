class Solution {
    public int coinChange_rec(int[] coins, int amount,int[] dp) {
        if(amount == 0)
            return dp[amount]= 0;
        
        
        if(dp[amount] != 0)
            return dp[amount];
        
        int c = (int)1e8;
        for(int i=0;i<coins.length;i++)
        {
            if(amount - coins[i] >= 0)
            {
                c = Math.min(c,coinChange_rec(coins,amount-coins[i],dp)+1);
            }
        }
        return dp[amount] = c;
    }
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        Arrays.fill(dp,0);
        int c = coinChange_rec(coins,amount,dp);
        //return c;
        if(c==(int)1e8)
            return -1;
        else
            return c;
    }
}
