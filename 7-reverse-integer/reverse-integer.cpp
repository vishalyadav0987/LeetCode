class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int lastDigit=0;
        while(x!=0){
            lastDigit = x % 10;
            // here comes the special case
            // INT_MAX = 2147483647
            // INT_MIN = -2147483647
            // if we reverse the above it should be gone out of range
            if ((rev > INT_MAX /10) || rev < INT_MIN /10){
                return 0;
            }
            rev = rev * 10 + lastDigit;
            // remove the lastDigit from X
            x = x/10;
        }
        return rev;
    }
};