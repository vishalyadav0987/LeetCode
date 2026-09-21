class Solution {
public:
    set<vector<int>> st;
    void getAllCombinationSum(vector<int>& nums, int target, int idx, vector<vector<int>>& ans, vector<int>& combine){
        // base case
        if(idx == nums.size() || target < 0){
            return;
            // target < 0 never happens 1 <= target <= 40
        }

        if(target == 0){
            if(st.find(combine)== st.end()){
                ans.push_back(combine);
                st.insert(combine);
            }
            return;
            
        }

        // Single element include case
        combine.push_back(nums[idx]);
        getAllCombinationSum(nums,target-nums[idx],idx+1,ans,combine);
        // multiple element include case -- means again push same element with increase idx
        getAllCombinationSum(nums,target-nums[idx],idx,ans,combine);
        // back to exclude case 
        combine.pop_back();

        //exclude case 
        getAllCombinationSum(nums,target,idx+1,ans,combine);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        getAllCombinationSum(nums,target,0,ans,combine);
        return ans;
    }
};