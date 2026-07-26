class Solution {
public:
    bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int st=0;
        int end = n-1;
        while(st<end){
            if(s[st] == s[end]){
                st++;end--;
            }else{
                return isPal(s, st+1, end) || isPal(s, st, end - 1);
            }
        }
        return true;
    }
};