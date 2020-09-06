class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (const int x : nums) {
            one ^= x & ~two;
            two ^= x & ~one;
        }
        return one;
    }
};
