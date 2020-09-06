class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> indegree(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j])
                    indegree[x][y]++;
            }

    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (indegree[i][j] == 0)
                que.push({i, j});

    int len = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();

            for (int d = 0; d < 4; d++)
            {
                int x = rvtx.first + dir[d][0];
                int y = rvtx.second + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[rvtx.first][rvtx.second] && 
                    --indegree[x][y] == 0)
                    que.push({x, y});
            }
        }
        len++;
    }

    return len == 0 ? -1 : len;
}
};
