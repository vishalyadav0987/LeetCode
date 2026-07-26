class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "AIEUOaieou";
        int st=0;
        int end = s.size()-1;
        while(st<end){
            if(!vowels.contains(s[st])){
                st++;
            }else if(!vowels.contains(s[end])){
                end--;
            }else if(vowels.contains(s[st]) && vowels.contains(s[end]) ){
                swap(s[st++],s[end--]);
            }
        }

        return s;
    }
};