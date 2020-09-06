class NumArray {
    int[] pre = new int[10000];
    public NumArray(int[] nums) {
        if(nums.length == 0)
            return;
        pre[0] = nums[0];
        for(int i=1;i<nums.length;i++)
        {
            pre[i] = nums[i] + pre[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        if(i==0)
            return this.pre[j];
        return this.pre[j] - this.pre[i-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
