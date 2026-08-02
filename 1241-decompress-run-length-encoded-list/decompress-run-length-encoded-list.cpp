class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=1;i<n;i++){
            int freq = nums[i-1];
            int val = nums[i];
            int j  = 0;
            while(i < n && j < freq){
                ans.push_back(val);
                j++;
            };
            i++;
        }
        return ans;
    }
};