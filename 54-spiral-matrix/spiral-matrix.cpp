class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        // 1. we print "TOP Row" part of matrix  (0,m-1)
        // 2. we print "RIGHT Col" part of matrix (m-1,n-1)
        // 3. we print "BOTTOM Row" part of matrix (n-1,m-1)
        // 4. we print "LEFT Col" part of matrix (m-1,0)

        int stRow = 0, stCol = 0, endRow = m-1, endCol=n-1;
        vector<int> ans;
        while(stRow <= endRow && stCol <= endCol){
            // top
            for(int i=stCol; i<=endCol;i++){
                ans.push_back(matrix[stRow][i]);
            }

            // when we print top row already 1,2,3 will push array
            // so we start right part stRow+1

            // right
            for(int i=stRow+1; i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
            }

            // bottom
            for(int i=endCol-1; i>=stCol;i--){
                // If only one row is left, the top row traversal has already
                // printed it. Breaking avoids printing the same row again.
                if(stRow==endRow){
                    break;
                }
                ans.push_back(matrix[endRow][i]);
            }

            // left
            for(int i=endRow-1; i>=stRow+1;i--){
                // If only one column is left, the right column traversal has
                // already printed it. Breaking avoids printing the same column again.
                if(stCol==endCol){
                    break;
                }
                ans.push_back(matrix[i][stCol]);
            }

            stRow++; stCol++; endRow--; endCol--;

        }

        // What in While Condition here two cases fall
        // written in notes.

        return ans;
        
    }
};