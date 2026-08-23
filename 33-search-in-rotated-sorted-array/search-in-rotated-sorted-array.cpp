class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Again doing 23-August-2026
        int n=nums.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            // checking which part sorted 
            // 1. condition for Left part softed
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[st] <= nums[mid]){
                // searching in left part
                if(nums[st] <= target && target <= nums[mid]){
                    end = mid - 1;
                }else{
                    st = mid + 1;
                }
            }
            // 2. Right part softed
            else{
                // searching in right part
                if(nums[mid] <= target && target <= nums[end]){
                    st = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};