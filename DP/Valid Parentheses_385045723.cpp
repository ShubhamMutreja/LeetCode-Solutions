class Solution {
public:
    bool isValid(string s) {
        stack<char> st; bool ss = false;
        if(s=="")
            return true;
        
        for(auto &e:s)
        {
            if(e == '(' || e == '[' || e == '{')
            {
                st.push(e);
                ss = true;
            }
            else if(e == ')')
            {
                if(st.empty() == true || st.top() != '(' )
                    return false;
                st.pop();
            }
            else if(e == ']')
            {
                if(st.empty() == true || st.top() != '[' )
                    return false;
                st.pop();
            }
            else if(e == '}')
            {
                if(st.empty() == true || st.top() != '{' )
                    return false;
                st.pop();
            }
        }
        return st.empty() == true ? true:false;
    }
};
