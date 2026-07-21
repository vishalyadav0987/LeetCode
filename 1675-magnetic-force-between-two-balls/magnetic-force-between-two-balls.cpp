class Solution {
public:
    bool isPossible(vector<int>& position, int m,int minimumAllowDistance){
        sort(position.begin(),position.end());
        int magnetCnt = 1;
        int lastMagnet = position[0];
        for(int i=1;i<position.size();i++){
            if((position[i] - lastMagnet) >= minimumAllowDistance ){
                lastMagnet=position[i];
                magnetCnt++;
            }
            if(magnetCnt == m) return true;
        }

        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int st=1; // minimum distance should place magnet is 1
        int end = *max_element(position.begin(),position.end()) - *min_element(position.begin(),position.end()); // max of array - min of array = distance should place magnet
        int ans=-1;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPossible(position,m,mid)){
                ans = mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }

        return ans;
    }
};