class Solution {
    int m,n;
    public int recur(int sr,int sc,int[][] dungeon,int[][] dp)
    {
        if(sr == n-1 && sc == m-1)
        {
            return dp[sr][sc] = Math.max(1,1-dungeon[sr][sc]);
        }
        
        if(dp[sr][sc] != 0)
            return dp[sr][sc];
        
        int min = (int)1e8;
        if(sr<n-1)
            min = Math.min(min,recur(sr+1,sc,dungeon,dp));
        if(sc<m-1)
            min = Math.min(min,recur(sr,sc+1,dungeon,dp));
        min -= dungeon[sr][sc];
        
        return dp[sr][sc] = Math.max(1,min);
    }
    public int calculateMinimumHP(int[][] dungeon) {
        n = dungeon.length;
        m = dungeon[0].length;
        int[][] dp = new int[n][m];
        return recur(0,0,dungeon,dp);
    }
}