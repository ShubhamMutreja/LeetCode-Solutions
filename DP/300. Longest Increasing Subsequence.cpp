class Solution {
public:
    int recur(vector<int> &arr,int n,int *dp)
    {
        if(dp[n] != -1)
            return dp[n];
        int len=1;
        for(int i = n; i >= 0;i--)
        {
            if(arr[n] > arr[i])
                len = max(len,recur(arr,i,dp)+1);
        }
        return dp[n] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        int max_len = 0;
        for(int i=0;i<n;i++)
        {
            max_len = max(max_len,recur(nums,i,dp));
        }
        return max_len;
    }
};