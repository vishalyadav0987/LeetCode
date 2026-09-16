class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Horizontal checking
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                if (st.count(board[i][j])) {
                    return false;
                }

                st.insert(board[i][j]);
            }
        }

        // Vertical checking
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;

            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;

                if (st.count(board[j][i])) {
                    return false;
                }

                st.insert(board[j][i]);
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                unordered_set<char> st;

                for (int sr = i; sr < i + 3; sr++) {
                    for (int sc = j; sc < j + 3; sc++) {

                        if (board[sr][sc] == '.')
                            continue;

                        if (st.count(board[sr][sc])) {
                            return false;
                        }

                        st.insert(board[sr][sc]);
                    }
                }
            }
        }
        return true;
    }
};