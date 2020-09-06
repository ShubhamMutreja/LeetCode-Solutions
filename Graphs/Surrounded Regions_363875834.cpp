class Solution {
public:
    vector<vector<int>> dir{{0,-1},{0,1},{1,0},{-1,0}};

void solve_(vector<vector<char>> &grid,int sr,int sc)
{
    grid[sr][sc] = '#';
    for(int d=0;d<4;d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 'O')
        {
            solve_(grid,r,c);
        }
    }
}
void solve(vector<vector<char>> &grid)
{
    if(grid.size() == 0 || grid[0].size() == 0)
    {
        return;
    }
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++)
    {
        if(grid[i][0] == 'O')
        {
            solve_(grid,i,0);
        }
        if(grid[i][m-1] == 'O')
        {
            solve_(grid,i,m-1);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(grid[0][i] == 'O')
        {
            solve_(grid,0,i);
        }
        if(grid[n-1][i] == 'O')
        {
            solve_(grid,n-1,i);
        }
    }
    for(int i=0;i<grid.size();i++)
    {
        for(int j = 0; j<grid[0].size();j++)
        {
            if(grid[i][j] == 'O')
            {
                grid[i][j] = 'X';
            }
            else if(grid[i][j] == '#')
            {
                grid[i][j] = 'O';
            }
        }
    }
    
}
};
