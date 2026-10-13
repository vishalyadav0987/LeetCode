class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int ci=i%n;
            while(st.size() > 0 && nums[st.top()%n] <= nums[ci]){
                st.pop();
            }

            ans[ci] = st.size() == 0 ? -1: nums[st.top()%n];
            st.push(i);
        }

        return ans;
    }
};