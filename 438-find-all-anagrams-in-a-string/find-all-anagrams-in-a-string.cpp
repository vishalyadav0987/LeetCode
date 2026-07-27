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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ansIdx;
        int freq[26] = {0};
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
        } 

        int windowSize = p.length();
        for(int i=0;i<s.length();i++){
            int stIdx = i;
            int windIdx = 0, windStIdx = i;
            int windFreq[26] = {0};
            while(windIdx < windowSize && windStIdx<s.length() ){
                windFreq[s[windStIdx]-'a']++;
                windStIdx++;
                windIdx++;
            }

            if (isFreqSame(freq,windFreq)){
                ansIdx.push_back(stIdx);
            }else{
                stIdx = 0;
            }
        }

        return ansIdx;
    }
};