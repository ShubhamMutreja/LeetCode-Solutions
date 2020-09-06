class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length()+1];
        memset(dp,0,sizeof dp); int m = 0;
        for(int i = 1;i<s.length();i++)
        {
            int j = i - dp[i] - 1;
            if(s[i] == ')' && j >= 0 && s[j] == '(')
                dp[i+1] = dp[i] + dp[j] + 2;
            m = max(m,dp[i+1]);
        }
        return m;
    }
};
