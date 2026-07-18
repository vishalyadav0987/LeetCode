class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = INT_MAX;
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            // Left Part Sorted
            if(nums[st] <= nums[mid]){
                minVal=min(minVal,nums[st]);
                st=mid+1;
            }else if(nums[mid] <= nums[end]){
                minVal=min(minVal,nums[mid]);
                end=mid-1;
            }
        }

        return minVal;
    }
};