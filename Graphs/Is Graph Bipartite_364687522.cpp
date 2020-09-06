class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> C(n,-1);
    for(int i =0;i<n;i++)
    {
        if(C[i] == -1)
        {
            queue<int> q;
            q.push(i);
            C[i] = 1; 
            while(!q.empty())
            {
                int vt = q.front();
                q.pop();
            
                for(int i=0;i<graph[vt].size();++i)
                {
                    if(C[graph[vt][i]] == -1)
                    {
                        C[graph[vt][i]] = C[vt] == 0? 1:0;
                        q.push(graph[vt][i]);
                    }
                    else if(C[graph[vt][i]] == C[vt])
                    {
                        return false;
                    }
                }
            }
            
        }
    
    }
    return true;
}
};
