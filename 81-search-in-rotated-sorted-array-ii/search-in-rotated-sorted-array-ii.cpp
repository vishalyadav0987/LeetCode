class Solution {
public:
    // 153
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            // checking which part sorted 
            // 1. condition for Left part softed
            if(nums[mid] == target){
                return true;
            }else if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
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

        return false;
    }
};