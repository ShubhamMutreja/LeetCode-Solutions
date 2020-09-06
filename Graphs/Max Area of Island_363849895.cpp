class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
    int dfs(vector<vector<int>>& grid,int sr,int sc)
    {
        grid[sr][sc] = 0;
        int area = 0;
        for(int i=0;i<4;i++)
        {
            int r = sr +  dir[i][0];
            int c = sc +  dir[i][1];                          
            
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 1)
            {
                area+=(dfs(grid,r,c));
            }
        }
        return area+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    maxarea = max(maxarea,dfs(grid,i,j));
                }
            }
        }
        return maxarea;
    }
};
