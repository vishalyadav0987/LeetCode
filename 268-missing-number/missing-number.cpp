class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumOfN = (n * (n+1))/2;
        int sumOfA = accumulate(nums.begin(), nums.end(), 0);
        return sumOfN - sumOfA;
    }
};