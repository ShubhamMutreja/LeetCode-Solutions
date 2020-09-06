class Solution {
public:
    int dfs(int src,vector<bool> &vis,vector<vector<int>>& g)
    {
        vis[src] = true; int ans = 0;
        for(auto e : g[src])
        {
            if(!vis[abs(e)])
            {
                ans+=dfs(abs(e),vis,g);
                if(e>0)
                    ans++;
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(100005);
        for(auto e : connections)
        {
            int u = e[0];
            int v = e[1];
            
            graph[u].push_back(v);
            graph[v].push_back(-u);
        }
        vector<bool> vis(100005,false);
        return dfs(0,vis,graph);
    }
};
