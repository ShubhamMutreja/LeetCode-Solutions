class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        def isvalid(arr,n,k,mid):
            d = 1; summ = 0;
            for i in range(n):
                summ+=arr[i]
                if summ > mid:
                    summ = arr[i]
                    d+=1
                if d>k:
                    return False
            return True
        
        end = sum(weights); start = max(weights); n =len(weights); res = -1;
        while(start<=end):
            mid = (start + end)//2
            if(isvalid(weights,n,D,mid)):
                res = mid
                end = mid-1
            else:
                start = mid+1
        
        return res
