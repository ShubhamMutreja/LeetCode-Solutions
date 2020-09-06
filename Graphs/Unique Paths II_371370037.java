class Solution {
    public int memo1(int m,int n,int[][] dp,int[][] obstacleGrid)
    {
        if(m<0 || n<0)
            return 0;
        if(obstacleGrid[m][n] == 1)
            return dp[m][n] = 0;
        if(m==0 && n==0)
            return dp[m][n] = 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = memo1(m-1,n,dp,obstacleGrid) + memo1(m,n-1,dp,obstacleGrid); 
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length; int n = obstacleGrid[0].length;
        
        int[][] dp2d = new int[m][n];
        
        if(obstacleGrid[0][0] == 1)
            return 0;

        //memo1(m-1,n-1,dp2d,obstacleGrid);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp2d[i][j] = 1;
                    continue;
                }
            
                if(dp2d[i][j] != 0)
                    continue;
                if(obstacleGrid[i][j] == 1)
                {
                    dp2d[i][j] = 0;
                    continue;
                }
                if(i-1>=0)
                {
                    //dp2d[i][j] = 0;
                    dp2d[i][j] += dp2d[i-1][j];
                }
                if(j-1>=0)
                {
                    //dp2d[i][j] = 0;
                    dp2d[i][j] += dp2d[i][j-1];
                }
            }
        }
        return dp2d[m-1][n-1];
    }
    
}
