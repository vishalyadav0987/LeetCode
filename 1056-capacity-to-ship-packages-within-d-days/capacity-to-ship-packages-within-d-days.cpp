class Solution {
public:
    bool isValidCapacity(vector<int>& weights, int days, int minimumCapacity){
        int daysToShip=1;
        int capacity=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > minimumCapacity) return false;
            if(weights[i] + capacity > minimumCapacity){
                capacity=0;
                daysToShip++;
            }
            capacity+=weights[i];
            if(daysToShip > days) return false;
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st=0;
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isValidCapacity(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        return ans;
    }
};