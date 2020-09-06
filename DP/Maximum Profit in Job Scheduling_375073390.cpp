class Solution {
public:
    struct p
    {
        int start;
        int end;
        int profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<p> st;
        for(int i=0;i<startTime.size();i++)
        {
            st.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(st.begin(),st.end(),[](struct p &a,struct p &b)
             {
                 return a.end < b.end;
             });
        int n = startTime.size();
        int mx = 0; int dp[n]; dp[0] = st[0].profit;
        for(int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1],st[i].profit);
            for(int j=i-1;j>=0;j--)
            {
                if(st[i].start >= st[j].end)
                {
                    dp[i] = max(dp[i],dp[j]+st[i].profit);
                    break;
                }
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};
