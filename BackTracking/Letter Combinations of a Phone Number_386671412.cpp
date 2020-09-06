class Solution {
public:
    string words[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string s)
    {
        if(s.length() == 0)
            return {};
        return fun(s);
    }
    vector<string> fun(string digits) {
        if(digits.length() == 0)
        {
            vector<string> base;
            base.push_back("");
            return base;
        }
        char ch = digits[0];
        string s = digits.substr(1);
        string word = words[ch - '0'];
        vector<string> smol = fun(s);
        vector<string> ans;
        for(auto &s : smol)
        {
            for(int i=0;i<word.length();i++)
            {
                ans.push_back(word[i] + s);
            }
        }
        return ans;
    }
};
