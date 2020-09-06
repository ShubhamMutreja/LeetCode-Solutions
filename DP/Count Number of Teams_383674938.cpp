class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int dp[n];
        int dp1[n];
        memset(dp,0,sizeof dp);
        memset(dp1,0,sizeof dp1);
        int res=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(rating[j] < rating[i])
                {
                    res += dp[j];
                    dp[i]++;
                }
                else if(rating[j] > rating[i])
                {
                    res+=dp1[j];
                    dp1[i]++;
                }
            }
        }
        return res;
    }
};
