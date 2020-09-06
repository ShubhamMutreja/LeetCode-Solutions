class Solution {
public:
    int ser(vector<int>& arr, int target,int l,int h)
    {
        if(l>h)
            return -1;
        int mid = (l+h)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[l] <= arr[mid])
        {
            if(target >= arr[l] && target<=arr[mid])
                return ser(arr,target,l,mid-1);
            return ser(arr,target,mid+1,h);
        }
        if(target >= arr[mid] && target <= arr[h])
            return ser(arr,target,mid+1,h);
        return ser(arr,target,l,mid-1);
    }
    int search(vector<int>& nums, int target) {
        return ser(nums,target,0,nums.size()-1);
    }
};