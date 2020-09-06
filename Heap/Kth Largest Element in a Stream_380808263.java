class KthLargest {
    PriorityQueue<Integer> p = new PriorityQueue<>();
    int K;
    public KthLargest(int k, int[] nums) {
        this.K = k;
        for(int ele:nums)
        {
            add(ele);
        }
    }
    
    public int add(int val) {
        p.add(val);
        if(p.size()>this.K)
            p.remove();
        return p.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
