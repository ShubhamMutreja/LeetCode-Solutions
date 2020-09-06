class Solution {
    public int minTriangulation(int[] arr,int si,int ei,int[][] dp)
    {
        if(ei-si<2) 
            return 0;

        if(dp[si][ei] != -1)
            return dp[si][ei];
        
        int minAns = (int)1e8;
        for(int cut = si+1;cut<ei;cut++)
        {
            int left = minTriangulation(arr,si,cut,dp);
            int right = minTriangulation(arr,cut,ei,dp);

            int myAns = left + right + arr[si]*arr[cut]*arr[ei];
            minAns = Math.min(minAns,myAns);
        }
        return dp[si][ei] = minAns;
    }
    public int minScoreTriangulation(int[] A) {
        int[][] dp = new int[A.length][A.length];
        for(int[] d: dp)
            Arrays.fill(d,-1);
        return minTriangulation(A,0,A.length-1,dp);
    }
}
