class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
               c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    
    string sortVowels(string s) {
        string vowelStr= "";
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                vowelStr+=s[i];
            }
        }
        sort(vowelStr.begin(), vowelStr.end());
        int idx=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i] = vowelStr[idx++];
            }
        }
        return s;
    }
};