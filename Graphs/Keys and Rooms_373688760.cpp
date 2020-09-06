class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool> &vis,int src)
    {
        vis[src] = true;
        for(auto &e:rooms[src])
            if(!vis[e])
                dfs(rooms,vis,e);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        dfs(rooms,vis,0);
        for(auto e:vis)
            if(e == false)
                return false;
        return true;
    }
};
