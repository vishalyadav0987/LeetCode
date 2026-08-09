class Solution {
public:
    int bs(vector<int>& nums, int tar, int st, int end) {
        if (st > end)
            return -1;

        int mid = st + (end - st) / 2;

        if (nums[mid] == tar) {
            return mid;
        }

        if (nums[mid] < tar) {
            return bs(nums, tar, mid + 1, end);
        } else {
            return bs(nums, tar, st, mid - 1);
        }
    }

    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        return bs(nums, target, st, end);
    }
};