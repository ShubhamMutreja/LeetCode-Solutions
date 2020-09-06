class Solution {
    public void display(int[] arr)
    {
        for(int e : arr)
            System.out.print(e+" ");
    }
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] count = new int[n];
        
        int mlen = 0; int mcount = 0;
        for(int i=0;i<n;i++)
        {
            dp[i] = 1; count[i] = 1;
            for(int j = i-1;j>=0;j--)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j]+1)
                        count[i] += count[j];
                }
            }
            if(dp[i] > mlen)
            {
                mlen = dp[i];
                mcount=count[i];
            }
            else if(dp[i] == mlen)
            {
                mcount += count[i];
            }
        }
        return mcount;
    }
}
