class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp = vector<vector<int>>(31,vector<int>(1001,-1));
    int numRollsToTarget(int d, int f, int target) 
    {
        if(d==0 && target==0)
        {
            return 1;
        }
        if(dp[d][target] != -1)
            return dp[d][target]%mod;
        long long int c = 0;
        for(int i=1;i<f+1;i++)
        {
            if(target - i >= 0 && d-1 >= 0)
            {
                c += (numRollsToTarget(d-1,f,target - i)%mod);
            }
        }
        return dp[d][target] = c%mod;
    }
};