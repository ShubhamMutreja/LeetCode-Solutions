class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> map; int maxl = 0;
        for(int ele:nums) 
            map.insert(ele);
        
        for(int ele:nums)
        {
            if(map.find(ele) == map.end())
            map.erase(ele);
            int prev = ele-1;
            int next = ele+1;
            
            while(map.find(prev) != map.end())
            {
                map.erase(prev);
                prev--;
            }
            
            while(map.find(next) != map.end())
            {
                map.erase(next);
                next++;
            }
            maxl = max(maxl,next-prev-1);
        }
        return maxl;
    }
};
