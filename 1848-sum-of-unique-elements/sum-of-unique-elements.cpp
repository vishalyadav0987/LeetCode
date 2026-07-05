class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int sumOfUnique = 0;

        for (auto x : mpp){
            if(x.second < 2){
                sumOfUnique += x.first;
            }
        }

        return sumOfUnique;
    }
};