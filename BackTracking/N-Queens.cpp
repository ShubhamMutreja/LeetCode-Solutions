class Solution {
public:
    vector<vector<string>> queen;
    vector<string> res;
    vector<bool> col,diag,adig;
    int recur(int r,int n,int que,int colm = -1)
    {
        if(que == 0)
        {
            queen.push_back(res);
            return 1;
        }
        
        int co = 0; string ans = "";
        for(int c = 0;c<n;c++)
        {
            if((col[c] && diag[c+r] && adig[r - c + n -1]))
            {
                col[c] = !col[c];
                diag[c+r] = !diag[c+r];
                adig[r - c + n -1] = !adig[r - c + n -1];
                for(int i=0;i<n;i++)
                {
                    ans+= i == c ? 'Q' : '.';
                }
                res.push_back(ans);
                co+= recur(r+1,n,que-1);
                res.pop_back(); ans = "";
                col[c] = !col[c];
                diag[c+r] = !diag[c+r];
                adig[r - c + n -1] = !adig[r - c + n -1];
            }
        }
        return co;
    }
    vector<vector<string>> solveNQueens(int n) {
        col.assign(n,true);
        diag.assign(n+n-1,true);
        adig.assign(n+n-1,true);
        //queen.assign()
        recur(0,n,n);
        
        return queen;
    }
};