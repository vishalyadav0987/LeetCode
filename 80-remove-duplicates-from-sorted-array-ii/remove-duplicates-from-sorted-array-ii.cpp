class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // again doing 24-August-2026
        if(nums.size() < 3) return nums.size();
        int j = 2;
        for(int i =2;i<nums.size();i++){
            if(nums[i] != nums[j-2]){
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};