class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int target,int row){
        int n = matrix[0].size();
        int st = 0;
        int end = n-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1. if we flattern these 2d array the all element in Increasing Order
        // 2. Flatten Array [1,3,5,7,10,11,16,20,23,30,34,60]
        // 3. if array is sorted then We apply "Binary Search"
        // 4. for 2d array decrese the search space is main approach of "BS"
        // 5. Check target row[0][0] >= target && <= row[0][n-1]
        // 6. if target lies in single row then we apply class "bs" appraoch

        int m = matrix.size();
        int n = matrix[0].size();

        int stRow = 0;
        int endRow = m-1;

        while(stRow <= endRow){
            int midRow = stRow + (endRow - stRow)/2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                // apply classic "BS" on single Row;
                return bs(matrix, target, midRow);
            }else if(target >= matrix[midRow][n-1]){
                // go DownWard in 2d array
                stRow = midRow + 1;
            }else{
                endRow = midRow - 1;
            }
        }

        return false;
    }
};