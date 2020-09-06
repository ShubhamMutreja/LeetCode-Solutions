class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int minstockprice = (int)1e8;
        int maxProfit = 0;
        
        for(int i=0;i<n;i++)
        {
            maxProfit = Math.max(maxProfit,prices[i] - minstockprice);
            minstockprice = Math.min(minstockprice,prices[i]);
            
        }
        return maxProfit;
    }
}
