
class Solution {
public:
    
    int numTrees(int n) {
        //2nCn
        unsigned long int res=1;
        for(int i=0;i<n;i++)
        {
            res *= (2*n - i);
            res /= (i+1);
        }
        return res/(n+1);
    }
};
