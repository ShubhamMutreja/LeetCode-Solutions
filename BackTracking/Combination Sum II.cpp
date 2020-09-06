class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<bool> vis;
    int recur(vector<int>& arr, int target,int idx)
    {
        if(target == 0)
        {
            ans.push_back(res);
            return 1;
        }
        
        int count = 0;
        for(int i=idx;i<arr.size();i++)
        {
            if(i > idx && arr[i] == arr[i-1])
                continue;
            if(target - arr[i] >= 0)
            {
                res.push_back(arr[i]);
                count += recur(arr,target-arr[i],i+1);
                res.pop_back();
            }
        }
        return count;
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        sort(arr.begin(),arr.end());
        cout<<recur(arr,target,0);
        return ans;
        
    }
};