class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0;i<nums.size(); i++){
            int ele = nums[i];
            int cnt = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] == ele){
                    cnt++;
                }
            }

            if(cnt > nums.size() / 2){
                return ele;
            }
        }

        return -1;
    }
};