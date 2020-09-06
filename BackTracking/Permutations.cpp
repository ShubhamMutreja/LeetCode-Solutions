class Solution {
public:
    vector<vector<int>> res;
    vector<int> smoll;
    
    void recur(vector<int> &arr, vector<bool> &vis, int count = 0)
    {
        if(count == arr.size())
        {
            res.push_back(smoll);
            return;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                smoll.push_back(arr[i]);
                recur(arr,vis,count+1);
                smoll.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<bool> vis(nums.size(),false);
        recur(nums,vis);
        return res;
    }
};