import sys

def fun(e,f):
    if f==1 or f==0 or e==1:
        return f
    dp = [[0 for i in range(e+1)] for j in range(301)]
    
    for i in range(1,301):
        for j in range(1,e+1):
            dp[i][j] = 1 + dp[i-1][j-1] + dp[i-1][j]
            if dp[i][j]>=f:
                return i
    

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        return fun(K,N)
        
