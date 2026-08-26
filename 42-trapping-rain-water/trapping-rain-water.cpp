class Solution {
public:
    int trap(vector<int>& h){
        // Again doing 26-August-2026
        int n = h.size();
        int left=0;
        int right=n-1;
        int maxLeft=0;
        int maxRight=0;
        int ans=0;
        while(left<right){
            if(h[left] >= h[right]){
                if(h[right] > maxRight){
                    maxRight=h[right];
                }else{
                    ans+=maxRight-h[right];
                }
                right--;
            }else{
                if(h[left] > maxLeft){
                    maxLeft=h[left];
                }else{
                    ans+=maxLeft-h[left];
                }
                left++;
            }
        }
        return ans;
    }
};