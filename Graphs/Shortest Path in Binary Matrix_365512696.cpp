class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return -1;
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        return -1;

    int dirA[8][2] = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};
    queue<int> que;
    que.push(0);

    int level = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            int R = (rvtx / m);
            int C = (rvtx % m);

            if (R == n - 1 && C == m - 1)
                return level;

            for (int d = 0; d < 8; d++)
            {
                int r = R + dirA[d][0];
                int c = C + dirA[d][1];

                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 0)
                {
                    grid[r][c] = 1;
                    que.push((r * m + c));
                }
            }
        }
        level++;
    }

    return -1;
}
};
