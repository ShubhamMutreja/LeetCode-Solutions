class Solution {
public:
    vector<int> par;
    int findPar(int src)
    {
        if(src == par[src])
        return src;
        return par[src] = findPar(par[src]);
    }
    int findCircleNum(vector<vector<int>> &M)
{
    for (int i = 0; i < M.size(); i++)
        par.push_back(i);

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[0].size(); j++)
        {
            if (M[i][j] == 1 && i != j)
            {
                int p1 = findPar(i);
                int p2 = findPar(j);

                if (p1 != p2)
                    par[p1] = p2;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < M.size(); i++)
    {
        if (par[i] == i)
            count++;
    }

    return count;
}
};
