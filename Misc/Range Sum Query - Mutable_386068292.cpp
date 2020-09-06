class NumArray {
public:
    vector<int> tree; int n;
    void construct(vector<int>& nums,int s,int e,int pos)
    {
        if(s > e) return;
        if(s == e)
        {
            tree[pos] = nums[s];
            return;
        }
        int m = (s+e)/2;
        construct(nums,s,m,2*pos+1); 
        construct(nums,m+1,e,2*pos+2);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        int x = 4*n;
        int size = x;
        tree.resize(size);
        //fill(tree.begin(),tree.end(),0);
        construct(nums,0,n-1,0);
    }
    void update_(int pos,int l, int r, int s, int e,int val)
    {
        if(l < s || r > e)
            return;
        if(s == e)
        {
            tree[pos] = val;
            return;
        }
        int m = (s+e)/2;
        update_(2*pos+1,l,r,s,m,val);
        update_(2*pos+2,l,r,m+1,e,val);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
        return;
    }
    void update(int i, int val) {
        update_(0,i,i,0,n-1,val);
    }
    int sum(int pos,int l,int r,int s, int e)
    {
        if(l > e || r < s)
            return 0;
        if(l<=s && r >=e)
            return tree[pos];
        int m = (s+e)/2;
        
        int left_ans = sum(2*pos+1,l,r,s,m);
        int right_ans= sum(2*pos+2,l,r,m+1,e);
        return left_ans + right_ans;
    }
    int sumRange(int i, int j) {
        return sum(0,i,j,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
