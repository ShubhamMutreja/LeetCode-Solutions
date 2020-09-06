class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto &ele : nums)
        {
            x = (x ^ ele); 
        }
        return x;
    }
};
