class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            // edge cases
            // 0. if array have single element
            // [1]
            if(n==1) return nums[0];
            // 1. if single element on first
            // [1,2,2,3,3,4,4]
            if(nums[0] != nums[1]) return nums[0];
            // 1. if single element on last
            // [1,1,2,2,3,3,4,4,5]
            if(nums[n-2] != nums[n-1]) return nums[n-1];

            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            // mid ke both side even no's of element hai
            // [1,1,2,3,3,4,4,8,8]
            // mid = 4 // on right [4,4,8,8]
            else if (mid % 2 == 0) {
                if (nums[mid - 1] != nums[mid]) {
                    st = mid - 1;
                } else {
                    end = mid + 1;
                }
            }
            // mid ke both side odd no's of element hai
            // [4,4,7,7,10,11,11]
            // mid = 3 // on right [10,11,11]
            else {
                if (nums[mid - 1] != nums[mid]) {
                    end = mid + 1;
                } else {
                    st = mid - 1;
                }
            }
        }

        return -1;
    }
};