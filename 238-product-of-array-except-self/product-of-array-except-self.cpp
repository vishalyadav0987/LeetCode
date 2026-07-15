class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int cntZero = 0;
        int productExceptZero = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cntZero++;
            } else {
                productExceptZero *= nums[i];
            }
            if (cntZero == 2) {
                productExceptZero *= 0;
            }
            product *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (cntZero >= 2) {
                nums[i] = nums[i] * 0;
            } else if (cntZero == 1) {
                if (nums[i] != 0) {
                    nums[i] = 0 * nums[i];
                } else {
                    nums[i] = productExceptZero;
                }
            } else {
                nums[i] = product / nums[i];
            }
        }

        return nums;
    }
};