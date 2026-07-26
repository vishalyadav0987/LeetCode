class Solution {
public:
    string finalString(string s) {
        string output="";
        int i=0;
        while(i < s.size()){
            if(s[i] == 'i'){
                reverse(output.begin(), output.end());
            }else{
                output+=s[i];
            }
            i++;
        }

        return output;
    }
};