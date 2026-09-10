class Solution {
public:
    void getUniqueSubsets(vector<int>& nums,vector<int>& ans, int i,vector<vector<int>>& allSubsets){
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        // include the element
        ans.push_back(nums[i]);
        getUniqueSubsets(nums,ans,i+1,allSubsets);

        // exclude case - remove element
        ans.pop_back();

        // Special case - sorted array
        // [1,2,2,3]
        // when i=1, when pop the element in exclude case then in i=2 we again include same
        // element is 2
        int idx = i+1;
        while(idx < nums.size() && nums[idx-1] == nums[idx]) idx++;
        getUniqueSubsets(nums,ans,idx++,allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<vector<int>> allSubsets;
        getUniqueSubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
};