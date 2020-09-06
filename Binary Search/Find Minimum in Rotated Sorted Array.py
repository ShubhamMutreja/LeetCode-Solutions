class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        l = 0; r = n-1;
        while l <= r:
            m =  l + (r-l)//2
            nex = (m+1)%n
            pre = (m+n-1)%n
            if nums[m] <= nums[nex] and nums[m] <= nums[pre]:
                return nums[m]
            
            if nums[m] <= nums[r]:
                r = m-1
            elif nums[l] <= nums[m]:
                l = m+1