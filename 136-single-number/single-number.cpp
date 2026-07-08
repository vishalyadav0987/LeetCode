class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleEle = 0;
        for(int i=0;i<nums.size();i++){
            singleEle ^= nums[i];
        }

        return singleEle;
    }
};