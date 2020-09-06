class Solution {
    public int minPlaindromicCut_bestMethod(String str,int si,int ei,int[] dp,boolean[][] palindromicSubstring){
        if(palindromicSubstring[si][ei]) return 0;
        if(dp[si] != -1) return dp[si];
        
        int minCut=(int)1e8;
        for(int cut = si; cut < ei; cut++){
            if(palindromicSubstring[si][cut]){
              minCut = Math.min(minCut,minPlaindromicCut_bestMethod(str,cut+1,ei,dp,palindromicSubstring)+1);
            }            
        }

        return dp[si]=minCut;
    }

    public int minCut(String str) {
        int n = str.length();
        int[] dp=new int[n];
        boolean[][] isPalindrome=new boolean[n][n];

        Arrays.fill(dp,-1);

        for (int gap = 0; gap < n; gap++) {
            for (int si = 0, ei = gap; ei < n; si++, ei++) {
                if (gap == 0) isPalindrome[si][ei] = true;
                else if (str.charAt(si) == str.charAt(ei) && gap == 1) isPalindrome[si][ei] = true;
                else isPalindrome[si][ei] = str.charAt(si) == str.charAt(ei) && isPalindrome[si + 1][ei - 1];
            }
        }

        return minPlaindromicCut_bestMethod(str,0,n-1,dp,isPalindrome);
    }
}
