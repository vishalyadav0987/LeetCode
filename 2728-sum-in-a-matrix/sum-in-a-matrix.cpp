class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        int totalScore = 0;
        // re solved these question
        for (int i = 0; i < c; i++) {
            int maxEle = -1;
            for (int j = 0; j < r; j++) {
                int maxOFRow = *max_element(nums[j].begin(), nums[j].end()); 
                maxEle = max(maxEle, maxOFRow);
                int idx = max_element(nums[j].begin(), nums[j].end()) -
                          nums[j].begin();
                nums[j].erase(nums[j].begin() + idx);
            }

            totalScore += maxEle;
        }

        return totalScore;
    }
};