class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // [-18, -12, -1, 4, 10, 13, 17, 20]
        int productRight = nums[n-1] * nums[n-2] * nums[n-3];
        // negative + negative  = postive + right most bigger element
        int productLeft = nums[0] * nums[1] * nums[n-1];
        return max(productRight,productLeft);
    }
};