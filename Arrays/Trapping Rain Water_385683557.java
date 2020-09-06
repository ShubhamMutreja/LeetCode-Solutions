class Solution {
    public int trap(int[] height) {
        Stack<Integer> st = new Stack<Integer>();
        int n = height.length;
        int water=0;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[i] > height[st.peek()])
            {
                int h = height[st.peek()];
                st.pop();
                if(st.empty()) break;
                int w = i - st.peek() -1;
                water += (Math.min(height[st.peek()],height[i]) - h)*w;
            }
            st.push(i);
        }
        
        return water;
    }
}
