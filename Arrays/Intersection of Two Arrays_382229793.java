class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> mp = new HashSet<>();
        HashSet<Integer> ans = new HashSet<>();
        for(int ele : nums1)
            mp.add(ele);
        
        for(int ele : nums2)
        {
            if(mp.contains(ele) && ans.contains(ele) == false)
            {
                ans.add(ele);
            }
        }
        System.out.println(ans);
        int[] arr = new int[ans.size()];
        int i= 0;
        for(int e : ans)
        {
            arr[i] = e;
            i++;
        }
        return arr;
            
    }
}
