class Solution {
public:
    vector<int> res;
    vector<vector<int>> ans;
    vector<bool> vis;
    int recur(int n, int k,int j)
    {
        if(k == 0 && n == 0)
        {
            ans.push_back(res);
            return 1;
        }
        if(k<=0 || n<=0)
            return 0;
        int c = 0;
        for(int i=j;i<10;i++)
        {
            if(!vis[i] && n-i >= 0)
            {
                res.push_back(i);
                vis[i] = true;
                c += recur(n-i,k-1,i+1);
                res.pop_back();
                vis[i] = false;
                
            }
        }
        return c;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vis.assign(10,false);
        recur(n,k,1);
        return ans;
    }
};