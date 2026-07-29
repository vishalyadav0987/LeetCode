class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i=0;i<n;i++){
            int presentChar = chars[i];
            int count = 0;
            while(i<n && presentChar == chars[i]){
                count++;
                i++;
            }

            // if count is 1 only put character not Count
            if(count == 1){
                chars[idx++] = presentChar;
            }else{
                chars[idx++] = presentChar;
                string strCount = to_string(count); 
                // if count should be "12" use same like that "1", "2"
                for(char digit : strCount){
                    chars[idx++] = digit;
                }
            }

            i--;
            // because when character equal i++ in while loop but when character
            // not matachs for loop i++ will that case we i-- to back to next
            // character position
            // ["a","a","b","b","c","c","c"]
        }

        chars.resize(idx);
        return idx;
    }
};