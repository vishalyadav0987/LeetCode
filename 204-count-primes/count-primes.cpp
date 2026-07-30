class Solution {
public:
    int countPrimes(int n) {
        // The Algorithum name is "Sieve of Eratosthenes"
        // what actually Alogo, ye maan lete hai 2 to n tak sabhi will be prime
        // 2, 3, 4, 5, 6, 7, 8, 9, 10
        // 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
        // 21, 22, 23, 24, 25, 26, 27, 28, 29, 30
        // 31, 32, 33, 34, 35, 36, 37, 38, 39, 40
        // 41, 42, 43, 44, 45, 46, 47, 48, 49, 50
        // we run loop 2 to n then we choose first number is 2 and 2 is prime
        // and then mark all multiple is isPrime = false,

        vector<bool> isPrime(n+1, true);
        int count = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                // why i*2 like we have i=3 so is prime so we want cancel multiple of
                // the next multiple will 3*2 = 6
                for(int j=i*2;j<n;j=j+i){
                    isPrime[j]=false;
                }
            }
        }

        return count;
    }
};