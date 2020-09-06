class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
    int n = numCourses;
    vector<vector<int>> graph(n,vector<int>());
    vector<int> inDeg(n,0);
    for(vector<int> &ar : prerequisites)
    {
        graph[ar[0]].push_back(ar[1]);
        inDeg[ar[1]]++;
    }
    queue<int> q;
    vector<int> ans;
    //int count = 0;
    for(int i=0;i<n;i++)
    {
        if(inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while(q.size() != 0)
    {
        int r = q.front(); 
        q.pop();
        //count++;
        ans.push_back(r);
        for(int e : graph[r])
        {
            if(--inDeg[e] == 0)
            {
                q.push(e);
            }
        }
    }
    if(ans.size()!=n)
    {
        ans.clear();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
};
