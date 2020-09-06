class Solution {
    public static int LIS_Rec(int[] arr,int ei,int[] dp)
    {
        if(dp[ei] != 0)
            return dp[ei];
        int maxlen = 1;
        for(int i=ei;i>=0;i--)
        {
            int len = 1;
            if(arr[i] < arr[ei])
            {
                len = LIS_Rec(arr,i,dp);
                maxlen = Math.max(maxlen,len+1);
            }

        }
        return dp[ei] = maxlen;
    }
    public int lengthOfLIS(int[] nums)
    {
        int n=nums.length;
        int[] dp = new int[n];
        int max = 0;
        for(int i=n-1;i>=0;i--)
        {
            max = Math.max(LIS_Rec(nums,i,dp),max);
        }
        return max;
    }
}
