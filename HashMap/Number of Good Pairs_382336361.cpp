class Solution {
public:
    int sum(int n)
    {
        return n*(n-1)/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int &ele : nums)
        {
            mp[ele]++;
        }
        int ans=0;
        for(auto &key : mp)
        {
            int n = key.second;
            if(n>1)
                ans+=sum(n);
                
        }
        return ans;
    }
};
