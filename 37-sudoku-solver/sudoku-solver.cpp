class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        // horizontal checking
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }

        // vertically checking
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }

        // grid check 3x3 here trick follow 
        // trick : every row and col value multiple of three;
        // so we find starting row and col value of grid where we currently present
        int stRow = (row/3) * 3;
        int stCol= (col/3) * 3;

        for(int sr=stRow;sr<=stRow+2;sr++){
            for(int sc=stCol;sc<=stCol+2;sc++){
                if(board[sr][sc] == dig){
                    return false;
                }
            }
        }


        return true;
    }
    // these problem like nQueens
    bool solve(vector<vector<char>>& board, int row, int col) {
        // we follow to fill row in every case so last row 8
        // then base case is if row == 9
        if (row == 9) {
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        // if column reach 9 it row+1 col=0
        if (col == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // skip that case that already filed
        if (board[row][col] != '.') {
            return solve(board, nextRow, nextCol);
        }

        // we placing value every time on empty place and check it safe to place
        // to steps flow
        // 1. horizontally 2. vertically 3. in 3x3 grid

            for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col,dig)) {
                board[row][col] = dig;
                if(solve(board, nextRow, nextCol)){
                    return true;
                }
                // if value not placable back to previous state where last value
                // placed and revert to "." and again trying place new value
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};