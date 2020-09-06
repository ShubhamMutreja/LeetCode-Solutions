class Solution {
public:
    int dp[1005][1005];
    int fun(vector<int>& piles,int l, int r)
    {
        if(dp[l][r] != -1)
            return dp[l][r];
        if(l == r-1)
            return max(piles[l],piles[r]);
        
        int rs = piles[r] + max(fun(piles,l+2,r),fun(piles,l+1,r-1));
        int ls = piles[l] + max(fun(piles,l+1,r-1),fun(piles,l,r-2));
        
        return dp[l][r] = max(ls,rs);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int a = fun(piles,0,n-1);
        if(a > sum -a)
            return true;
        return false;
    }
};
