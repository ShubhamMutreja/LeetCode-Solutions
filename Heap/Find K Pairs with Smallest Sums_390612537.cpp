class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
    priority_queue<vector<int>> pq;
    for(auto &ele1 : nums1)
    {
        for(auto &ele2 : nums2)
        {
            int sum = ele1 + ele2;
            if(pq.size() < k)
                pq.push({sum,ele1,ele2});
            else if(sum<pq.top()[0])
            {
                pq.pop();
                pq.push({sum,ele1,ele2});
            }
        }
    }
    vector<vector<int>> ans;
    while(!pq.empty())
    {
        ans.push_back({pq.top()[1],pq.top()[2]});
        pq.pop();
    }
    return ans;
    }
};
