class Solution {
public:
    vector<int> par;
    vector<int> size;
    int find(int src)
    {
        if(src == par[src])
            return src;
        return par[src] = find(par[src]);
    }
    void merge(int p1,int p2)
    {
        if(size[p1] > size[p2])
        {
            par[p2] = par[p1];
            size[p1]+=size[p2];
        }
        {
            par[p1] = par[p2];
            size[p2]+=size[p1];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.size() == 0 || edges[0].size() == 0)
            return {};
        int n = edges.size();
        //vector<vector<int>> graph(n,vector<int>());
        
        
        for(int i=0;i<=n+1;i++)
        {
            par.push_back(i);
            size.push_back(1);
        }
        
        for(vector<int> &e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            int p1 = find(u); int p2 = find(v);
            
            if(p1 != p2)
            {
                //merge(p1,p2);
                par[p1] = p2;
            }
            else
            {
                return e;
            }
        }
        return {};
    }
};
