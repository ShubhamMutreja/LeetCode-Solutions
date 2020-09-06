class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
     
        for(auto & ch : num)
        {
            while(!st.empty() && st.top() > ch && k>0)
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(!st.empty() && k>0)
        {
            st.pop(); k--;
        }
        string ans= "";
        
        while(!st.empty())
        {
            ans += st.top(); st.pop();
        }
        while(ans.size() != 0)
        {
            if(ans.back() != '0')
                break;
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        return ans.length() == 0 ? "0":ans;
    }
};
