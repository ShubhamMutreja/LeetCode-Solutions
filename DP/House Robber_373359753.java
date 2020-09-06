class Solution {
    public int recur(int[] nums,int n,int[] dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return dp[n] = nums[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = Math.max(recur(nums,n-2,dp)+nums[n],recur(nums,n-1,dp));
    }
    public int rob(int[] nums) {
        if(nums.length==0)
            return 0;
        int[] dp = new int[nums.length+1];
        for(int i=0;i<nums.length;i++)
            dp[i] = -1;
        return recur(nums,nums.length-1,dp);
    }
}
