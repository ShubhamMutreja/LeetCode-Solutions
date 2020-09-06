class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0)
            return 0;
        
        sort(envelopes.begin(),envelopes.end(),[](const vector<int> &a,const vector<int> &b)->bool
             {
                 if(a[0] == b[0])
                     return a[1] > b[1];
                 return b[0] > a[0];
             });
        int ans = 0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};