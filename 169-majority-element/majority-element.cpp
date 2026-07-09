class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // better approch
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                cnt++;
            }else{
                cnt = 1;
                ans = nums[i];
            }
            if(cnt > nums.size()/2) return ans;
        }

        
        return -1;
    }
};