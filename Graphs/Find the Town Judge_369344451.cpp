class Solution {
public:
    
    int findJudge(int N, vector<vector<int>>& trust) {
        
       // v/ector<vector<int>> graph(N, vector<int>());

        vector<int> in(N+1, 0);
        vector<int> out(N+1, 0);
        for (vector<int> &ar : trust)
        {
            //graph[ar[0]].push_back(ar[1]);
            in[ar[1]]++;
            out[ar[0]]++;
        }
        int i;
        for(i=1;i<N+1;i++)
        {
            if(in[i] == N-1)
            {
                if(out[i] == 0)
                {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
