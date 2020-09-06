class Comparator{
public :
int operator()(pair<int,int> x, pair<int,int> y){
return (x.second>y.second);
}
};
class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int s) {
vector<vector<pair<int,int>> > graph(n+1,vector<pair<int,int>> ());

    for(int i=0;i<times.size();i++){
        graph[times[i][0]].push_back({times[i][1],times[i][2]}); //{destination,weight}
    }
    
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int> , vector<pair<int,int> >, Comparator> pq;
    vector<bool> visited(n+1,false);
    dist[s]=0;  visited[s]=true;
    pq.push({s,0});
    while(!pq.empty()){
        pair<int,int> top=pq.top();
        pq.pop();
        int u=top.first;
        int d=top.second;
        for(auto x : graph[u]){
            if(dist[u]!=INT_MAX && visited[x.first]==false && 
                   dist[x.first]>dist[u]+x.second){          //relaxation step
                dist[x.first]=dist[u]+x.second;
                pq.push({x.first,dist[x.first]});
            } 
        }
    }
    int max_time=0;
    for(int i=1;i<=n;i++)
        max_time=max(dist[i],max_time);
    return (max_time==INT_MAX) ? -1 : max_time;
}
};
