class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid)
{
    int n = grid.size();
    
    int m = grid[0].size();
        if(n == 0 || m == 0)
        {
            return 0;
        }
    queue<pair<int,int>> que;
    int Foranges=0;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j] == 2)
            {
                que.push({i,j});
            }
            else if(grid[i][j] == 1)
            {
                Foranges++;
            }
        }
    }
    if(Foranges == 0) return 0;
    int time = 0;
    while(que.size()!=0)
    {
        int size = que.size();
        while(size--)
        {
            pair<int,int> rvtx = que.front(); que.pop();
            for(int d=0;d<4;d++)
            {
                int r = rvtx.first + dir[d][0];
                int c = rvtx.second + dir[d][1];

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    que.push({r,c});
                    Foranges--;
                }
            }
        }
        time++;

    }
    return Foranges != 0? -1 : time-1;
}
};
