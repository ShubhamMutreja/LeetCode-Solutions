class Solution {
public:
    vector<bool> cols,diag,adig;
    int recur(int r,int n,int q)
    {
        if(q == 0)
            return 1;
        
        int count = 0;
        for(int col = 0;col<n;col++)
        {
            if(cols[col] && diag[r+col] && adig[r-col+n-1])
            {
                cols[col] = !cols[col];
                diag[r+col] = !diag[r+col];
                adig[r-col+n-1] = !adig[r-col+n-1];
                
                count += recur(r+1,n,q-1);
                
                cols[col] = !cols[col];
                diag[r+col] = !diag[r+col];
                adig[r-col+n-1] = !adig[r-col+n-1];
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        cols.assign(n,true);
        diag.assign(n+n-1,true);
        adig.assign(n+n-1,true);
        return recur(0,n,n);
    }
};