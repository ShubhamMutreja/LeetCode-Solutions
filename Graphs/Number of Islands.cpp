class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(char[][] grid,int rc,int cc)
    {
        grid[rc][cc] = '0';
        for(int i=0;i<dir.length;i++)
        {
            int r = rc + dir[i][0];
            int c = cc + dir[i][1];
            
            if(r>=0 && c>=0 && c<grid[0].length && r<grid.length && grid[r][c] == '1')
            {
                dfs(grid,r,c);
            }
        }
        
    }
    public int numIslands(char[][] grid) {
        if(grid.length == 0)
            return 0;
        int count = 0;
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
}