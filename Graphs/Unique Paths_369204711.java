class Solution {
    public static int memo1(int m,int n,int[][] dp)
    {
        if(m==0 && n==0)
            return dp[m][n] = 1;
        if(m<0 || n<0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = memo1(m-1,n,dp) + memo1(m,n-1,dp); 
    }
    public int uniquePaths(int m, int n) {
        int[][] dp2d = new int[m][n];
        
        for (int i = 0; i < dp2d.length; i++) {
            for (int j = 0; j < dp2d[i].length; j++) {
                dp2d[i][j] = -1;
            }
        }
        memo1(m-1,n-1,dp2d);
        return dp2d[m-1][n-1];
    }
}
