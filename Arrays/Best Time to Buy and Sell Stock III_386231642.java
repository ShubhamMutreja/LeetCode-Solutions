class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        
        int msp = prices[0]; int max=0;
        for(int i=1;i<n;i++)
        {
            msp = Math.min(msp,prices[i]);
            dp1[i] = Math.max(dp1[i-1],prices[i] - msp);
        }
        
        int maxat = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxat = Math.max(maxat,prices[i]);
            dp2[i]= Math.max(dp2[i+1],maxat - prices[i]);
        }
        for(int i=0;i<n;i++)
        {
            max = Math.max(max,dp1[i] + dp2[i]);
        }
        return max;
    }
}
