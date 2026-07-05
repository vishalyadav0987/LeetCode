class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i]) != mpp.end()){
                ans.push_back(nums2[i]);
                mpp.erase(nums2[i]);
            }
        }

        return ans;
        
    }
};