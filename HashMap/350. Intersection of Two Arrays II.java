class Solution {
    public int[] intersect(int[] nums1, int[] nums2) 
    {
        HashMap<Integer,Integer> mp = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();
        for(int ele : nums1)
            mp.put(ele,mp.getOrDefault(ele,0)+1);
        
        for(int ele : nums2)
        {
            if(mp.containsKey(ele) && mp.get(ele) > 0)
            {
                ans.add(ele);
                mp.put(ele,mp.get(ele)-1);
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