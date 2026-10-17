class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // here main trick is find width for every h[i]
        // So we find right and left smaller for every bar

        int n = h.size();
        stack<int>st;
        vector<int>right(n,0); // right smaller value (next greater element problem)
        vector<int>left(n,0); // left smaller value (previous smaller element problem)

        // next greater element concpet used here
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && h[st.top()] >= h[i]){
                st.pop();
            }

            // right[i] = st.empty() ? -1 : st.top();
            // why change -1 to n becuase if the right smaller not find and case so we last boundary 2,1,5,6,2,3 here for second 2 right is last.
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // previous smaller element concpet used here
        for(int i=0;i<n;i++){
            while(st.size() > 0 && h[st.top()] >= h[i]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }


        int ans = 0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int currArea = h[i] * width;
            ans = max(ans,currArea);
        }

        return ans;

    }
};