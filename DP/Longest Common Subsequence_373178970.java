class Solution {
    public static int LCS(String str, int n, String str2, int m, int[][] dp)
    {
        if(m==0 || n==0)
            return 0;
        if(dp[n][m] != 0)
            return dp[n][m];
        if(str.charAt(n-1) == str2.charAt(m-1))
            return dp[n][m] = LCS(str,n-1,str2,m-1,dp)+1;
        else
            return dp[n][m] = Math.max(LCS(str,n,str2,m-1,dp),LCS(str,n-1,str2,m,dp));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];
        return LCS(text1,text1.length(),text2,text2.length(),dp);
    }
}
