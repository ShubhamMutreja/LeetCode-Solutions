class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> C(N+1,-1);   
        vector<vector<int>> graph(N+1,vector<int>());
        for(auto ele : dislikes)
        {
            graph[ele[0]].push_back(ele[1]);
            graph[ele[1]].push_back(ele[0]);
        }
        for(int i =1;i<=N;i++)
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
            
                for(auto ele : graph[vt])
                {
                    if(C[ele] == -1)
                    {
                        C[ele] = 1-C[vt];
                        q.push(ele);
                    }
                    else if(C[ele] == C[vt])
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
