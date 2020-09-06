class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib({ 1, 1 });
    
        int n = 1;
        while (fib[n++] < k)
            fib.emplace_back(fib[n - 1] + fib[n - 2]);
        
        int ans = 0;
        while (k)
            if (fib[--n] <= k) {
                k -= fib[n];
                ++ans;
            }
        
        return ans;
    }
};
