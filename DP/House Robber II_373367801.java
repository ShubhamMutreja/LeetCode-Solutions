class Solution {
    public int recur(int[] nums,int n,int t,int[] dp)
    {
        if(n<t)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        if(n == t)
        {
            return dp[n] =nums[t];
        }
        return dp[n] = Math.max(nums[n]+recur(nums,n-2,t,dp),recur(nums,n-1,t,dp));
    }
    public int rob(int[] nums) {
        if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return nums[0];
        int[] dp = new int[nums.length];
        Arrays.fill(dp, -1);
        int l = recur(nums,nums.length-1,1,dp);
        Arrays.fill(dp, -1);
        int r = recur(nums,nums.length-2,0,dp);
        return Math.max(l,r);
    }
}
