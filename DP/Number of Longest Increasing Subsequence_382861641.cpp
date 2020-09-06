class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int dp[n];
        int cp[n];
        int maxl=0,maxc=0;
        for(int i = 0;i<n;i++)
        {
            dp[i] = 1; cp[i] = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        cp[i] = cp[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                    {
                        cp[i] = cp[i] + cp[j];
                    }
                }
            }
            if(dp[i] > maxl)
            {
                maxl = dp[i];
                maxc = cp[i];
            }
            else if(dp[i] == maxl)
            {
                maxc += cp[i];
            }
        }
        return maxc;
    }
};
