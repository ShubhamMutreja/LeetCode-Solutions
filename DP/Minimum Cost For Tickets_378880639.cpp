class Solution {
public:
    int dp[366];
    int recur(vector<int> &v,int ei,vector<int>& costs)
    {
        if(ei<1)
            return 0;
        if(dp[ei] != -1)
            return dp[ei];
        
        if(v[ei] == 0)
            return recur(v,ei-1,costs);
        
        return dp[ei] = min(recur(v,ei-1,costs)+costs[0] ,min(recur(v,ei-7,costs)+costs[1],recur(v,ei-30,costs
            )+costs[2]));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days[days.size()-1]+1;
        vector<int> v(size,0);
        for(int i=0;i<days.size();i++)
        {
            v[days[i]] = 1;
        }
        memset(dp,-1,sizeof dp);
        return recur(v,days[days.size()-1],costs);
    }
};
