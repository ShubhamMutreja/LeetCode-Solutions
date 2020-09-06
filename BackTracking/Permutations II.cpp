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
        int prev = -1e8;
        for(int i=0;i<arr.size();i++)
        {
            if(!vis[i] && prev != arr[i])
            {
                vis[i] = true;
                smoll.push_back(arr[i]);
                recur(arr,vis,count+1);
                smoll.pop_back();
                vis[i] = false;
                prev = arr[i];
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> vis(nums.size(),false); //for all calls
        recur(nums,vis);
        return res;
    }
};