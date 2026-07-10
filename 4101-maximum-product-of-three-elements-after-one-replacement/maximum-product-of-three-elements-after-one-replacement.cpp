class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // The extreme pairs from a sorted array
        long long p1 =
            1LL * nums[0] * nums[1]; // Two smallest (potential large negatives)
        long long p2 = 1LL * nums[n - 1] * nums[n - 2]; // Two largest positives
        long long p3 =
            1LL * nums[0] *
            nums[n -
                 1]; // Smallest and largest (potential large negative product)

        // Multiply every pair by the maximum possible replacements to find the
        // absolute max
        return max({p1 * 100000LL, p1 * -100000LL, p2 * 100000LL,
                    p2 * -100000LL, p3 * 100000LL, p3 * -100000LL});
    }
};