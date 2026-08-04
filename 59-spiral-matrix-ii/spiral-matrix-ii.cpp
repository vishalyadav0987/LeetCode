class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row = n;
        int col = n;
        int stRow = 0, stCol = 0, endRow = row-1, endCol = col-1;
        int filedRange = n*n;
        int val = 1;

        while(stRow <= endRow && stCol <=endCol && val <= filedRange){
            // top filed
            for(int i=stCol; i<=endCol;i++){
                ans[stRow][i]= val++;
            }

            // right filed
            for(int i=stRow+1; i<=endRow;i++){
                ans[i][endCol] = val++;
            }

            for(int i=endCol-1; i>=stCol;i--){
                if(stRow==endRow){
                    break;
                }
                ans[endRow][i]= val++;
            }

            // left
            for(int i=endRow-1; i>=stRow+1;i--){
                if(stCol==endCol){
                    break;
                }
               ans[i][stCol] = val++;
            }

            stRow++; stCol++; endRow--; endCol--;
        }

        return ans;
    }
};