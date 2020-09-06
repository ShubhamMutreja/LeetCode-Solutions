class Solution {
    public class pair
    {
        int x;
        int y;
        int dist;
        
        public pair(int x,int y)
        {
            this.x = x;
            this.y = y;
            this.dist = Math.abs(x*x + y*y);// + Math.abs(y);
        }
    }
    public int[][] kClosest(int[][] points, int K) {
        PriorityQueue<pair> pq = new PriorityQueue<>((a,b)->{
            return b.dist - a.dist;
        });
        for(int[] ele : points)
        {
            pq.add(new pair(ele[0],ele[1]));
            if(pq.size()>K)
                pq.remove();
        }
        int[][] ans = new int[K][2];
        while(K-- > 0)
        {
            pair rvtx = pq.remove();
            ans[K][0] = rvtx.x;
            ans[K][1] = rvtx.y;
        }
        return ans;
    }
}
