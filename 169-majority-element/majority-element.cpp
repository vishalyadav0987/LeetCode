class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // optimal approach moore voting algo
        int ans  = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }

        int freq = 0;
        for(int x: nums){
            if(x == ans){
                freq++;
            }
        }

        if(freq > nums.size() / 2) return ans;

        return -1;
    }
};