class Solution {
public:
    int swimInWater(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    typedef pair<int, int> pii; //{ele, i*m+j}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    pq.push({grid[0][0], 0});
    vis[0][0] = true;

    int ans = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while (pq.size() != 0)
    {
        pii rvtx = pq.top();
        pq.pop();

        int height = rvtx.first;
        int x = rvtx.second / m;
        int y = rvtx.second % m;
        
        ans = max(ans, height);
        if (x == n - 1 && y == m - 1) // destination
            return ans;

        for (int d = 0; d < 4; d++)
        {
            int r = x + dir[d][0];
            int c = y + dir[d][1];
            if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c])
            {
                vis[r][c] = true;
                pq.push({grid[r][c], r * m + c});
            }
        }
    }

    return ans;
}
};
