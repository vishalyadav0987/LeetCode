class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (numMap.find(i) == numMap.end()) {
                return i;
            }
        }
        
        return 1;
    }
};