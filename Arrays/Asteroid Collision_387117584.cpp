class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        
        for(auto &ele : arr)
        {
            if(ele>0)
            {
                st.push(ele);
            }
            
            while(!(st.empty()) && st.top() > 0 && st.top() < -ele)
            {
                st.pop();
            }
            if(!(st.empty()) && st.top() == -ele)
            {
                st.pop();
            }
            else if(st.empty() || st.top() < 0)
            {
                st.push(ele);
            }
        }
        vector<int> ans(st.size());
        for(int i = ans.size()-1;i>=0;i--)
        {
            ans[i] = st.top(); st.pop();
        }
        return ans;
    }
};
