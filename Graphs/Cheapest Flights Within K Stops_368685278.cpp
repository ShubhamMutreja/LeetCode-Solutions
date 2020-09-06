typedef pair<int,int> pii;
typedef vector<int> pqPair;
class Solution {
public:

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<vector<pii>> graph(n,vector<pii>()); //{wsf,src,stops}
    priority_queue<pqPair,vector<pqPair>,greater<pqPair>> p;

    for(auto & flight : flights) // add edge
        graph[flight[0]].push_back({flight[1], flight[2]});

    p.push({0,src,K+1});
    while(p.size() != 0)
    {
        pqPair rvtx = p.top(); p.pop();

        if(rvtx[1] == dst)
        {
            return rvtx[0];
        }
        if(rvtx[2] == 0)
            continue;

        for(pii e : graph[rvtx[1]])
        {
            p.push({rvtx[0] + e.second,e.first,rvtx[2] - 1});
        }
    }
    return -1;

}
};
