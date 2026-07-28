class Solution {
public:

    string reverseByType(string s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            if (isalpha(s[st]) && isalpha(s[end])) {
                swap(s[st], s[end]);
                st++;
                end--;
            } else if (!isalpha(s[st])) {
                st++;
            } else if (!isalpha(s[end])) {
                end--;
            }
        }

        st=0;
        end = s.size() - 1;
        while (st < end) {
            if (!isalpha(s[st]) && !isalpha(s[end])) {
                swap(s[st], s[end]);
                st++;
                end--;
            } else if (isalpha(s[st])) {
                st++;
            } else if (isalpha(s[end])) {
                end--;
            }
        }

        return s;
    }
};