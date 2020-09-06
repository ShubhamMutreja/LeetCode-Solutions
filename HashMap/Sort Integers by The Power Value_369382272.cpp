class Solution {
public:
    unordered_map<int,int> dp;
    int get(int n)
    {
        if(n == 1)
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n]-1;
        if(!(n&1))
            return dp[n/2] = get(n/2)+1;
        else
            return dp[3*n + 1] = get(3*n + 1)+1;
    }
    int getKth(int lo, int hi, int k) {
        //memset(dp,-1,sizeof dp);
        vector<vector<int>> p;
        for(int i=lo;i<=hi;i++)
            p.push_back({get(i),i});
        //cout<<get(12)<<" "<<get(13);
        sort(p.begin(),p.end());
        
        return p[k-1][1];
    }
};
