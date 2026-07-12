class Solution {
public:
    double myPow(double x, int e) {
        double ans = 1.0;
        long long n = e;
        if (n < 0) {
            n = -n; // Safe negation because n is now long long
            x = 1.0 / x; // Invert base to handle negative exponent
        }
        while(n > 0){
            if(n%2==1){
                ans*=x;
            }
                x*=x;
                n/=2;
           
        }

        return ans;
    }
};