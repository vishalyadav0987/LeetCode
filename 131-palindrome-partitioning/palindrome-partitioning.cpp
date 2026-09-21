class Solution {
public:
    bool palindromeHelper(string ps){
        int i=0,j=ps.size()-1;
        while(i<=j){
            if(ps[i] != ps[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans){
        // base case when string became empty
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }

        // question logic we add partition and check left and right
        // if left part palindrom then we move right partition
        // if left side not palindrom then cut next index.
        for(int i=0;i<s.size();i++){
            string ps = s.substr(0,i+1);
            if(palindromeHelper(ps)){
                partitions.push_back(ps);
                // move to right part string
                getAllParts(s.substr(i+1),partitions,ans);
                partitions.pop_back(); // remove last insearted answer
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s,partitions,ans);
        return ans;
    }
};