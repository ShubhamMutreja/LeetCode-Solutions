class Solution {
    public int fun(int[] arr,int si,int ei,int[][] dp)
    {
        if(dp[si][ei] != -1)
        {
            return dp[si][ei];
        }
        
        int lval = si==0 ? 1:arr[si-1];
        int rval = ei==arr.length-1 ? 1:arr[ei+1];
        
        int gl = 0;
        for(int cut = si;cut<=ei;cut++)
        {
            int l = cut==si ? 0:fun(arr,si,cut-1,dp);
            int r = cut==ei ? 0:fun(arr,cut+1,ei,dp);
            
            gl = Math.max(gl,l+r+ rval*lval*arr[cut]);
        }
        return dp[si][ei] = gl;
    }
    public int maxCoins(int[] nums) {
        if(nums.length == 0)
            return 0;
        int[][] dp = new int[nums.length][nums.length];
        for(int[] a: dp)
            Arrays.fill(a,-1);
        return fun(nums,0,nums.length-1,dp);
    }
}
