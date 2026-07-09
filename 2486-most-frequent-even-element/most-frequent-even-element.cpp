class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mpp[nums[i]]++;
            }
        }

        int maxFreqEle = -1;
        int cnt = -1;
        for(auto x: mpp){
            if(x.second > cnt){
                maxFreqEle = x.first;
                cnt = x.second;
            }
        }

        return maxFreqEle;
    }
};