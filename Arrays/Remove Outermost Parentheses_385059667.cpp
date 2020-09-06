class Solution {
public:
    string removeOuterParentheses(string S) {
        string s = "";
        int count = 0;
        for(auto e:S)
        {
            if(e == '(' && count++ > 0)
            {
                s += e;
            }
            else if(e == ')' && count-- > 1)
            {
                s += e;
            }
        }
        return s;
    }
};
