class Solution {
    public class pair
    {
        int val;
        int i;
        int j;
        
        public pair(int val,int i,int j)
        {
            this.val = val;
            this.i = i;
            this.j = j;
        }
    }
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<pair> p = new PriorityQueue<>((a,b)->{
            return a.val - b.val;
        });
        for(int i=0;i<matrix.length;i++)
        {
            p.add(new pair(matrix[i][0],i,0));
        }
        while(k-- > 1)
        {
            pair rvtx = p.peek();
            p.remove();
            if(rvtx.j+1 < matrix[0].length)
            {
                p.add(new pair(matrix[rvtx.i][rvtx.j+1],rvtx.i,rvtx.j+1)); 
            }
        }
        return p.peek().val;
    }
}