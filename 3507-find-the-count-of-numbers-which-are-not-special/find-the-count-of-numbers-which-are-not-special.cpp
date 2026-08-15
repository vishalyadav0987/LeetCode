class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int limit = sqrt(1000000000);
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        // Again Doing same Question 15 Aug 2026
        int special = 0;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                long long square = 1LL * i * i;

                if (square >= l && square <= r) {
                    special++;
                }
            }
        }

        return (r - l + 1) - special;
    }
};