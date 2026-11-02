class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        queue<char> q;
        for (auto ch : s) {
            q.push(ch);
        }
        int index = 0;
        while(!q.empty()){
            index++;
            if(freq[q.front() - 'a'] == 1){
                return index-1;
            }
            q.pop();
        }

        return -1;
    }
};