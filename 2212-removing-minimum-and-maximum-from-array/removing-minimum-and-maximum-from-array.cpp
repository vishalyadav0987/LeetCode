class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = -1;
        int maxIdx = -1;
        int len = nums.size();

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }

            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Ab agar hum har jagah minIdx aur maxIdx use karenge to formulas alag-alag banenge.Isliye hum pehle unhe sort kar dete hain.

        // Ab left hamesha chhota index hoga aur right hamesha bada index hoga, chahe minimum pehle aaye ya maximum.

        // three ways to remove
        // 1. both front
        // 2. both back
        // 3. back + front
        int front = right + 1;
        int back = len - left;
        int frontBack = (left + 1) + (len - right);

        int min1st = min(front,back);
        // cout << front<< " " << back << " " << frontBack; 
        return min(min1st, frontBack);

    }
};