class Solution {
public:
    vector<int> par;
    int find(int u)
    {
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    }
    int redundant = 0;
    int disconnet = 0;
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i =0;i<n;i++)
        {
            par.push_back(i);
        }
        
        for(auto &e : connections)
        {
            int p1 = find(e[0]);
            int p2 = find(e[1]);
            
            if(p1 != p2)
            {
                par[p1] = p2;
            }
            else
            {
                redundant++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(par[i] == i)
            {
                disconnet++;
            }
        }
        //cout<<disconnet<<" "<<redundant;
        return redundant>=disconnet-1 ? disconnet-1 : -1;
    }
};
