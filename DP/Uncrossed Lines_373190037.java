class Solution {
    public int DP(int[] A, int n, int[] B, int m, int[][] dp)
    {
        int M = m; int N = n;
        for(m=0;m<=M;m++)
        {
            for(n=0;n<=N;n++)
            {
                if(m==0 || n==0)
                {
                    dp[m][n] = 0;
                    continue;
                }
                if(A[n-1] == B[m-1])
                    dp[n][m] = dp[n-1][m-1]+1;
                else
                    dp[n][m] = Math.max(dp[n-1][m],dp[n][m-1]);
            }
        }
        return dp[N][M];
    }
    public int maxUncrossedLines(int[] A, int[] B) {
        int[][] dp = new int[A.length+200][B.length+200];
        return DP(A,A.length,B,B.length,dp);
    }
}
