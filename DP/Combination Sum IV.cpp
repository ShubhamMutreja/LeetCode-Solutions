class Solution {
public:
    unordered_map<int,int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
        {
            return 1;
        }
        int c = 0;
        if(dp.find(target) != dp.end())
            return dp[target];
        for(auto& i: nums)
        {
            if(target - i >= 0)
            {
                c += combinationSum4(nums,target - i);
            }
        }
        dp[target] = c;
        return c;
    }
};