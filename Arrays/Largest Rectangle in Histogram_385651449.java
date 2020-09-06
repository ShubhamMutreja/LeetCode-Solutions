class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<Integer>();
        st.push(-1); int max = 0;
        for(int i=0;i<n;i++)
        {
            while(st.peek() != -1 && heights[i] <= heights[st.peek()])
            {
                int h = heights[st.peek()]; st.pop();
                int w = i - st.peek() - 1;
                max = Math.max(max,h*w);
            }
            st.push(i);
        }
        
        while(st.peek() != -1)
        {
            int h = heights[st.peek()];
            st.pop();
            int w = n - st.peek() -1;
            max = Math.max(max,h*w);
        }
        return max;
    }
}
