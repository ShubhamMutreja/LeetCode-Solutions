class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto c: s)
            mp[c]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto &key : mp)
        {
            pq.push({key.second,key.first});
        }
        string ans = "";
        while(pq.size() != 0)
        {
            pair<int,char> pp = pq.top();
            char a = pp.second;
            int freq = pp.first;
            pq.pop();
            for(int i=0;i<freq;i++)
                ans += a;
        }
        return ans;
        
    }
};
