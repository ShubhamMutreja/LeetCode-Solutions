class Solution {
public:
    string removeDuplicateLetters(string text) {
        stack<char> st;
        vector<int> map(26,0);
        vector<bool> vis(26,false);
        for(char &ch : text)
        {
            map[ch-'a']++;
        }
        for(char &ch : text)
        {
            map[ch-'a']--;
            if(vis[ch-'a'] == true)
                continue;
            while(!st.empty() && st.top() > ch && map[st.top() - 'a'] > 0)
            {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            
            vis[ch-'a'] = true;
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
