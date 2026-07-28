class Solution {
public:
    bool isValidCharacter(string s, int st, int end) {
        return isalpha(s[st]) && isalpha(s[end]);
    }
    string reverseOnlyLetters(string s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            if (isValidCharacter(s,st,end)) {
                swap(s[st], s[end]);
                st++;
                end--;
            } else if (!isalpha(s[st])) {
                st++;
            } else if (!isalpha(s[end])) {
                end--;
            }
        }

        return s;
    }
};