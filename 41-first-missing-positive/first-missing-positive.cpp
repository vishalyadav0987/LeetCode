class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> numMap;
        int max_val = 0;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = true;
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (numMap.find(i) == numMap.end()) {
                return i;
            }
        }
        
        return 1;
    }
};