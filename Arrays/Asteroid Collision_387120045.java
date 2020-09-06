class Solution {
    public int[] asteroidCollision(int[] arr) {
        Stack<Integer> st = new Stack<Integer>();
        
        for(int ele : arr)
        {
            if(ele > 0)
            {
                st.push(ele);
                continue;
            }
            while(!(st.empty()) && st.peek() > 0 && st.peek() < -ele)
            {
                st.pop();
            }
            if(!(st.empty()) && st.peek() == -ele)
            {
                st.pop();
            }
            else if(st.empty() || st.peek() < 0)
            {
                st.push(ele);
            }
        }
        int[] ans = new int[st.size()];
        for(int i = ans.length-1;i>=0;i--)
        {
            ans[i] = st.peek(); st.pop();
        }
        return ans;
    }
}
