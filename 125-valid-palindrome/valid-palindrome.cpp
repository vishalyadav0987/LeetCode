class Solution {
public:
    bool isAlphanumeric(char s) {
        return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9');
    }
    bool isPalindrome(string s) {
        int st=0;
        int end=s.size()-1;
        while(st<end){
            if(!isAlphanumeric(s[st])){
                st++;
                continue;
            }if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }

        return true;
    }
};