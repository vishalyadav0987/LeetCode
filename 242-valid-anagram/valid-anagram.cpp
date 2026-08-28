class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
    bool isAnagram(string s, string t) {
        // Again doing 28-August-2026 
        int freq1[26] = {0};
        int freq2[26] = {0};

        if(s.length() != t.length()) return false; 

        for (int i = 0; i < t.length(); i++) {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }

        if (isFreqSame(freq1, freq2)) {
            return true;
        }

        return false;
    }
};