class Solution {
    public int maxSubArray(int[] nums) {
        int maxsofar=nums[0]; int temp=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            temp = Math.max(temp+nums[i],nums[i]);
            maxsofar = Math.max(maxsofar,temp);
        }
        return maxsofar;
    }
    
}
