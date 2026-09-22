class Solution {
public:

    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        // now copy temp element to original array and original place with
        // soreted form
        for (int idx = st; idx <= end; idx++) {
            nums[idx] = temp[idx - st];
        }

    }
    int countPairs(vector<int> &arr,int st, int mid,int end){
        int right = mid + 1;
        int left = st;
        int cnt=0;
        for(int i=left;i<=mid;i++){
            // agar essa nh hai 
            while(right <= end && arr[i] > 2LL*arr[right] ) right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int st, int end) {
        // base case
        if (st < end) {
            int mid = st + (end - st) / 2;

            // left side sort
            int leftInvCount = mergeSort(nums, st, mid);
            // right side sort
            int rightInvCount = mergeSort(nums, mid + 1, end);
            // merge the sorted parts
            int invCount = countPairs(nums,st,mid,end);
            merge(nums, st, mid, end);

            return leftInvCount + rightInvCount + invCount;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        // using merge Sort Algorithm
        return mergeSort(nums, 0, nums.size() - 1);
    }
};