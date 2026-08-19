class Solution {
public:
    int fib(int n) {
        // Again doing 19-August-2026
        if(n==0 || n==1) return n;
        return fib(n-1) + fib(n-2);
    }
};