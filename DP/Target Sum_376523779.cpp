class Solution {
public:
    int dp[1001][21];
    int recur(vector<int>& nums, int S,int n)
    {
      if(n == 0)
      {
        return S==0 ? 1:0;
      }
      // if(dp[S][n] != -1)
      //   return dp[S][n];
    
      return recur(nums,S-nums[n-1],n-1) + recur(nums,S+nums[n-1],n-1);
      
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp,-1,sizeof dp);
        int t = accumulate(nums.begin(),nums.end(),0);
        if(S>t)
          return 0;
        return recur(nums,S,nums.size());
    }
};
