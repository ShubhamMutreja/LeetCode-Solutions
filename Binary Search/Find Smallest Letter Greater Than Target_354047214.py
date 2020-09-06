class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = 0; r = len(letters)-1;
        k = "#"
        while(l<=r):
            mid = (l+r)//2
            if letters[mid] == target:
                l = mid+1
            elif letters[mid] < target:
                l = mid +1
            else:
                r = mid -1
                k = letters[mid]
        
        if letters[-1] <= target:
            return letters[0]
        else:
            return k
            
            
