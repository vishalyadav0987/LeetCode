class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1st way Sort Array use tow pointer ❌ because we want index
        // 2nd way prefix sum
        // 3rd  2 for loops
        unordered_map<int,int>mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[rem]);
            }

            mpp[nums[i]] = i;
        }

        return ans;
    }
};