
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,9999999);
        dp[0]= 0;
        for(int i= 1; i<dp.size();i++)
          {  for(int j =0;j<coins.size();j++)
            {
                if(coins[j]<=i)
                dp[i]=min(dp[i],dp[i-coins[j]]+1); 
            }cout<<dp[i]<<" ";
          }
            if(dp[dp.size()-1]==9999999)
                return -1;
        return dp[dp.size()-1];}
};
