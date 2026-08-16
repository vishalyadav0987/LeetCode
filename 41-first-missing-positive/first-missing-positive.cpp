class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min_pos = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] < min_pos) {
                min_pos = nums[i];
            }
        }
        if (min_pos > 1) {
            return 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Jab tak number 1 se N ke beech mein hai,
            // AUR wo apni sahi jagah par nahi hai (duplicate check)
            while (nums[i] > 0 && nums[i] <= nums.size() &&
                   nums[i] != nums[nums[i] - 1]) {

                // Number ko uske target index (nums[i] - 1) wali value ke saath
                // swap karo
                // again doing 16 August 2026
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 0;
        for(i=0;i<nums.size();i++){
            if(nums[i] == i+1){
                continue;
            }
            return i+1;
        }

        return i+1;
    }
};