class NumMatrix {
    int[][] sum;
    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        if(m==0)
            return;
        int n = matrix[0].length;
        if(n==0)
            return;
        sum = new int[m][n];
        if(sum.length == 0)
            return ;
        for(int i = 0;i < m;i++)
        {
            sum[i][0] = matrix[i][0];
            for(int j = 1;j < n;j++)
            {
                sum[i][j] = sum[i][j-1] + matrix[i][j];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        if(sum.length == 0)
            return 0;
        for(int i=row1;i<=row2;++i){
            int cur = (col1>0?(sum[i][col2] - sum[i][col1-1]): sum[i][col2]);
            ans += cur;
        }
        return ans;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
