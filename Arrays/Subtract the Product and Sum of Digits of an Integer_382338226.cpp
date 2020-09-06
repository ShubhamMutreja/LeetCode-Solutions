class Solution {
public:
    int product(int n)
    {
        int ans = 1;
        while(n>0)
        {
            ans *= (n%10);
            n = n/10;
        }
        return ans;
    }
    int sum(int n)
    {
        int ans = 0;
        while(n>0)
        {
            ans += (n%10);
            n = n/10;
        }
        return ans;
    }
    int subtractProductAndSum(int n) {
        return product(n) - sum(n);
    }
};
