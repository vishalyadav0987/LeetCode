class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i] - 'a']++; 
            // s1[0] = 'a' = 97
            // 'a'
            // s1[0] - 'a' == 'a' - 'a' = 0 index
        }

        // then search the s1 in s2 with same window side
        int windowSize = s1.length();
        for(int i=0;i<s2.length();i++){
            int windowIdx = 0 , idx = i;
            int windFreq[26] = {0};
            // search every window in s2
            // these condition for "idx < s2.length()"
            // if length of 5 and windowSize 3 when user go to 2nd window but length here but 
            // window size is 3 it will exceed.
            while(windowIdx < windowSize &&  idx < s2.length()){
                windFreq[s2[idx]-'a']++;
                windowIdx++;
                idx++;
            }

            // then check both array equal
            if(isFreqSame(freq,windFreq)){
                return true;
            }
        }

        return false;
    }
};