class Solution {
public:
    int dp[1001][1001];
    bool fun(string s1, string s2, string s3,int m,int n,int p)
    {
        if(m == s1.length() && n == s2.length() && p == s3.length())
            return true;
        bool res = false;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(m != s1.length())
        {
            if(s1[m] == s3[p])
                res = res || fun(s1,s2,s3,m+1,n,p+1);
        }
        if(n != s2.length())
        {
            if(s2[n] == s3[p])
                res = res || fun(s1,s2,s3,m,n+1,p+1);
        }
        return dp[m][n] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length();
        int b = s2.length();
        int c = s3.length();
        memset(dp,-1,sizeof dp);
        return fun(s1,s2,s3,0,0,0);
    }
};
