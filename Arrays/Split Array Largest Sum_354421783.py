class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def isvalid(arr,n,k,mid):
            d = 1; summ = 0
            for i in range(n):
                summ+=arr[i]
                if summ>mid:
                    d+=1
                    summ = arr[i]
                if d>k:
                    return False
            return True
        
        start = max(nums); end = sum(nums)
        res = -1
        n = len(nums)
        while(start<=end):
            mid = (start+end)//2
            if(isvalid(nums,n,m,mid)):
                res =mid
                end = mid-1
            else:
                start = mid+1
        
        return res
    #max(sum(nums[:res]),sum(nums[res:]))
                
