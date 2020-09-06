class Solution {
public:
  int dp[5001][1001];
  bool recur(vector<int>& nums, int S,int n)
    {
      if(n<0 || S<0)
          return false;
      if(n == 0 || S==0)
      {
        return S==0 ? true:false;
      }
      if (dp[S][n] !=  -1)
          return (bool)dp[S][n];
      
      
      return dp[S][n] = recur(nums,S,n-1) || recur(nums,S-nums[n-1],n-1);
      
    }
    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(),nums.end(),0);
        if(t%2 != 0)
            return false;
        memset(dp,-1,sizeof dp);
        return recur(nums,t/2,nums.size());
    }
};
