class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,0);
        vector<int> cp(n,0);
        int maxl = 0,maxc = 0;
        for(int i=0;i<n;i++)
        {
            cp[i] = 1;
            dp[i] = 1;
            for(int j = i-1;j>=0;j--)
            {
                if(arr[i] > arr[j])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cp[i] = cp[j];
                    }
                    else if(dp[j] +1 == dp[i])
                    {
                        cp[i] += cp[j];
                    }
                }
            }
            if(dp[i] > maxl)
            {
                maxl = dp[i];
                maxc = cp[i];
            }
            else if(maxl == dp[i])
            {
                maxc+=cp[i];
            }
        }
        return maxc;
    }
};
