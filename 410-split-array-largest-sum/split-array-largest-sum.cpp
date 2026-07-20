class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int k, int mid) {
        int studentCount = 1;
        int pageSum = 0;
        for (int i = 0; i < n; i++) {
            // edge case.
            if (nums[i] > mid)
                return false;
            if (nums[i] + pageSum > mid) {
                studentCount++;
                pageSum = 0;
            }
            pageSum += nums[i];
            if(studentCount>k) return false;
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int st = 0;
        int end = sum;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(nums, nums.size(), k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};