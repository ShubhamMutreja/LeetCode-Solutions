class Solution {
public:
    int dp[10000];
    int fun(string s,int i,int j)
    {
        if(i==j)
        {
            return 1;
        }
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int way1 = fun(s,i+1,j);
        int way2 = 0;
        
        if(i < j-1 && stoi(s.substr(i,2)) <= 26)
            way2 = fun(s,i+2,j);
        
        return dp[i] = way1 + way2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return fun(s,0,s.length());
    }
};
