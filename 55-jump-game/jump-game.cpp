class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        for(int currIdx = 0;currIdx<n;currIdx++){
            if(currIdx > farthest) return false;
            farthest = max(farthest , currIdx + nums[currIdx]);
            if(farthest >= n-1) return true;
        }
        return true;
    }
};