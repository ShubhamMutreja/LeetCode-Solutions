class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e8;
        
        int pro = 1; int n= nums.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,pro *= nums[i]);
            if(nums[i] == 0)
                pro = 1;
        }
        pro = 1;
        for(int i=n-1;i>=0;i--)
        {
            ans = max(ans,pro *= nums[i]);
            if(nums[i] == 0)
                pro = 1;
        }
        return ans;
    }
};