class Solution {
public:
    int dp[1001][1001];
    int recur(vector<vector<int>>& a,int r,int c)
    {
        if(r>= a.size() || c>=a[r].size())
            return 0;
        if(dp[r][c] != -1)
            return dp[r][c];
        return dp[r][c] =  a[r][c] + min(recur(a,r+1,c),recur(a,r+1,c+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
        return recur(triangle,0,0);
    }
};
