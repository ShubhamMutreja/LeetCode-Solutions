class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
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
            if(target - arr[i] >= 0)
            {
                res.push_back(arr[i]);
                count += recur(arr,target-arr[i],i);
                res.pop_back();
            }
        }
        
        return count;
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target,int start = 0) {
        cout<<recur(arr,target,0);
        return ans;
        
    }
};
