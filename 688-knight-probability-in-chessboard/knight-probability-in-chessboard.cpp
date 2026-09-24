class Solution {
public:
    double isVaildMove(vector<vector<vector<double>>>& dp, int r, int c, int n,
                       int k) {
        if (r < 0 || c < 0 || r >= n || c >= n || k < 0) {
            return 0;
        }

        if (k == 0) {
            return 1;
        }
        if (dp[r][c][k] != -1.0) {
            return dp[r][c][k];
        }

        double move1 = isVaildMove(dp, r - 2, c - 1, n, k - 1);
        double move2 = isVaildMove(dp, r - 2, c + 1, n, k - 1);
        double move3 = isVaildMove(dp, r - 1, c + 2, n, k - 1);
        double move4 = isVaildMove(dp, r + 1, c + 2, n, k - 1);
        double move5 = isVaildMove(dp, r + 2, c + 1, n, k - 1);
        double move6 = isVaildMove(dp, r + 2, c - 1, n, k - 1);
        double move7 = isVaildMove(dp, r + 1, c - 2, n, k - 1);
        double move8 = isVaildMove(dp, r - 1, c - 2, n, k - 1);

        return dp[r][c][k] = (move1 + move2 + move3 + move4 + move5 + move6 +
                              move7 + move8) /
                             8.0;
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp;
        dp = vector<vector<vector<double>>>(
            n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return isVaildMove(dp, r, c, n, k);
    }
};