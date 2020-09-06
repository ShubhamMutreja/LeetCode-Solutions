class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        
        for(auto c : strs)
        {
            int hash[26] = {0};
            
            for(int i = 0;i<c.size();i++)
                hash[c[i] - 'a']++;
            
            string ha;
            
            for(int i=0;i<26;i++)
            {
                ha += (hash[i]+'0');
            }
            mp[ha].push_back(c);
        }
        for (auto i = mp.begin() ; i != mp.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};
