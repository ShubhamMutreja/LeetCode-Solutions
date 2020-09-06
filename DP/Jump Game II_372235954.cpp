class Solution {
public:
    int recur(vector<int>& nums, int n,vector<int> &dp)
    {
        if(n >= nums.size()-1)
            return 0;
        
        int jumps = 1e8;
        
        if(dp[n] != -1)
            return dp[n];
        
        if(n < nums.size())
            for(int i=1;i<=nums[n];i++)
            {
                jumps = min(recur(nums,n+i,dp),jumps);
            }
        
        return dp[n] = jumps+1;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        if(nums.size() == 1)
            return 0;
        
        dp[0] = 0; dp[1] = nums[0];
        int i=2;
        while(dp[i-1] < nums.size()-1)
        {
            int tmp = 0;
            for(int j=dp[i-2] + 1; j<=dp[i-1];j++)
                tmp = max(tmp,nums[j]+j);
            dp[i] = tmp; i++;
        }
        return i-1;
        
    }
};
