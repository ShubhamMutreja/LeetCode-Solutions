class Solution {
public:
    int gcd(int a,int b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    bool isGoodArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0] == 1;
        int a = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(gcd(a,nums[i])==1)
                return true;
            a = gcd(a,nums[i]);
        }
        return false;
    }
};
