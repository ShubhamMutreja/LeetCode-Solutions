class Solution {
    public int longestPalindromeSubseq(String s) 
    {
        int[][] dp = new int[s.length()][s.length()];
        for(int i=0;i<s.length();i++)
            for(int j=0;j<s.length();j++)
                dp[i][j] = -1;
        return recur(s,0,s.length()-1,dp);
    }
    public int recur(String str,int i,int j, int[][] dp)
    {
        if(i > str.length()-1 || j<0)
            return 0;
        if(str.charAt(i) == str.charAt(j))
            return dp[i][j] = 1 + recur(str,i+1,j-1,dp);
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = Math.max(recur(str,i+1,j,dp) , recur(str,i,j-1,dp));

    }
}
