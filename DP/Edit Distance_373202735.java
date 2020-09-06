class Solution {
    public int recur(String s, String q, int n, int m,int[][] dp)
    {
        if(m==0 || n==0)
        {
            return n==0 ? m:n;
        }
        if(dp[n][m] != 0)
            return dp[n][m];
        
        if(s.charAt(n-1) == q.charAt(m-1))
            return dp[n][m] = recur(s,q,n-1,m-1,dp);
        else
        {
            int insert = recur(s,q,n,m-1,dp);
            int delete=  recur(s,q,n-1,m,dp);
            int replace =recur(s,q,n-1,m-1,dp);
            return dp[n][m] = Math.min(Math.min(insert,delete),replace) + 1;
        }
    }
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length()+1][word2.length()+1];
        return recur(word1,word2,word1.length(),word2.length(),dp);
    }
}
