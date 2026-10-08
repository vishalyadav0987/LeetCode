class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++) {
            mpp[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            auto it = mpp.find(nums1[i]);
            if (it != mpp.end()) {
                int index = it->second;
                int j = index + 1;
                if (index < nums2.size() - 1) {
                    for (j = index + 1; j < nums2.size(); j++) {
                        if (nums2[index] < nums2[j]) {
                            ans.push_back(nums2[j]);
                            break;
                        }else if(j==nums2.size()-1){
                            ans.push_back(-1);
                        }
                    }

                } else {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};