class Solution {
public:
    bool check(vector<int>& arr) {
        // again doing 18-August-2026
        int breakCnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] <= arr[i]) {
                continue;
            } else {
                breakCnt++;
            }
        }
        return breakCnt > 1
                   ? false
                   : ((arr[0] >= arr[arr.size() - 1] && breakCnt == 1) ||
                      breakCnt == 0);
    }
};