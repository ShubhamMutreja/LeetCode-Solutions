class Solution {
public:
    int minOperations(int n) {
        int minn = 1,r=0;
        int maxx = 2*(n-1) + 1;
        int mid = (minn + maxx)/2;
        
        for(int i=0;i<n/2;i++)
            r += mid - (2*i +1);
            
        return r;
    }
};
