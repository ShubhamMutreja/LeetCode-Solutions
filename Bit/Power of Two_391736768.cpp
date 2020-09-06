class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n < 0)
            return false;
        while(n)
        {
            n = (n&(n-1));
            count++;
            if(count > 1)
                return false;
        }
        if(count == 0)
            return false;
        return true;
    }
};
