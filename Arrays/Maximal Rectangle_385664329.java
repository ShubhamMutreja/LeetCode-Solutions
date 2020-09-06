class Solution {
    public int funforarea(int[] heights,int n)
    {
        Stack<Integer> st = new Stack<Integer>();
        st.push(-1); int max = 0;
        for(int i=0;i<n;i++)
        {
            while(st.peek() != -1 && heights[i] <= heights[st.peek()])
            {
                int h = heights[st.peek()];
                st.pop();
                int w = i - st.peek() -1;
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
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length; 
        if(n <= 0)
            return 0;
        int m= matrix[0].length;
        int[] heights = new int[m]; int max = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                heights[j] = matrix[i][j] == '1' ? heights[j] +1:0;
            }
            max = Math.max(max,funforarea(heights,m));
        }
    return max;
    }
}
