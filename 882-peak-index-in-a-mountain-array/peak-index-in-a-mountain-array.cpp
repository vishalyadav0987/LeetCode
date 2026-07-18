class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // What actually Peak mountain element-- "arr is guaranteed to be a mountain array."
        // arr[i-1] > arr[i] < arr[i+1]
        int st=1;
        int end=arr.size()-2;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }else if(arr[mid-1] < arr[mid]){
                st = mid+1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
};