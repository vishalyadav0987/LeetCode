class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        int maxFromLeft = values[0];
        for(int j=1;j<n;j++){
            ans=max(ans,maxFromLeft + (values[j]-j));
            maxFromLeft=max(maxFromLeft, values[j]+j);
        }

        return ans;
    }
};