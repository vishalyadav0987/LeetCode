class Solution {
public:
    // It is helper for queen place safe or not
    bool isSafe(vector<string>& board, int row, int col, int n){
        // horizontally
        for(int j=0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        // vertically
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // left diagonal --> top to bottom 
        for(int i=row,j=col; i>=0 && j>=0;j--,i--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // right diagonal --> bottom to top 
        for(int i=row,j=col; i>=0 && j<n;j++,i--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // note: we only check diagnal where queen place that point to bottom to up because if 
        // n = 4 and queen place in third row and we know that so why we check below diagnal of queen.

        return true;
    }
    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        // base case
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                nQueens(board,row+1,n,ans);
                board[row][j]='.'; // These case only runs when the queen place to faild in any row it back to that position again that row where we last queen place and function again start+1 from that point.
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nQueens(board,0,n,ans);

        return ans;
    }
};