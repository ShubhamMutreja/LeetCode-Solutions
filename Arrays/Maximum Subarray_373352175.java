class Solution {
    public int combine(int[] nums,int i,int m,int j){
        int sum = 0;
        int left_sum = (int)-1e8;
        
        for(int k=m;k>=i;k--)
        {
            sum+=nums[k];
            left_sum = Math.max(left_sum,sum);
        }
        
        sum = 0;
        int right_sum = (int)-1e8;
        
        for(int k=m+1;k<=j;k++)
        {
            sum+=nums[k];
            right_sum = Math.max(right_sum,sum);
        }
        
        return Math.max(Math.max(right_sum,left_sum),right_sum+left_sum);
    }
    public int divide(int[] nums,int i,int j)
    {
        if(i==j)
            return nums[i];
        int m = (i+j)/2;
        int l = divide(nums,i,m);
        int r = divide(nums,m+1,j);
        int gg= combine(nums,i,m,j);
        return Math.max(Math.max(l,r),gg);
    }
    public int maxSubArray(int[] nums) {
        // int maxsofar=nums[0]; int temp=nums[0];
        // for(int i=1;i<nums.length;i++)
        // {
        //     temp = Math.max(temp+nums[i],nums[i]);
        //     maxsofar = Math.max(maxsofar,temp);
        // }
        // return maxsofar;
        return divide(nums,0,nums.length-1);
        
    }
    
}
