class Solution {
public:
    string smallestSubsequence(string text) {
        if(text.length() <= 1)
            return text;
        int arr[26]; int seen[26];
        stack<char> st;
        memset(arr,0,sizeof arr);
        memset(seen,0,sizeof seen);
        for(char &ch : text)
        {
            arr[ch - 'a']++;
        }
        string ans = "";
        for(char &ch : text)
        {
            arr[ch - 'a']--;
            if(seen[ch - 'a'] == 1)
                continue;
            
            while(!st.empty() && st.top() > ch && arr[st.top() - 'a'] > 0)
            {
                seen[st.top() - 'a'] = 0;
                st.pop();
                
            }
            if(seen[ch - 'a'] == 0)
            {
                st.push(ch);
                seen[ch - 'a'] = 1;
                
            }
            
        }
        
        while(!st.empty())
        {
            ans = st.top() + ans;
            //cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
    }
};
