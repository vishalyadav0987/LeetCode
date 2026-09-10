class Solution {
public:
    void getAllSubstes(vector<int>& nums, vector<int> ans, int i,vector<vector<int>>& allSubstes ){
        // base case
        if(i == nums.size()){
            allSubstes.push_back(ans);
            return;
        }

        // include the number in array call first
        ans.push_back(nums[i]);
        getAllSubstes(nums,ans,i+1,allSubstes); // then increment the i

        // exclude call pop back the last number
        ans.pop_back();
        getAllSubstes(nums,ans,i+1,allSubstes); // then increment the i
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<vector<int>> allSubstes;
        vector<int> ans;
        getAllSubstes(nums,ans,i,allSubstes);

        return allSubstes;
    }
};