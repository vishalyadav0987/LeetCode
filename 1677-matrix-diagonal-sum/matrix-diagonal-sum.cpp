class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // again
        int n = mat[0].size();
        if(n==1) return mat[0][0];
        int sum = 0;
        for(int i=0;i<n;i++){
            // primary diagonal
            sum+=mat[i][i];
            // secondary diagonal
            sum+=mat[i][n-i-1];
        }

        if(n%2==1) return sum - mat[ceil(n/2)][ceil(n/2)];
        else return sum;

    }
};