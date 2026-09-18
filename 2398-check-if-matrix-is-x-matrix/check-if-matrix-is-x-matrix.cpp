class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& mat) {
        int n = mat[0].size();
        if(n==1) return mat[0][0] != 0;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            // primary diagonal || // secondary diagonal
            if(mat[i][i] == 0 || mat[i][n-i-1] == 0) return false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && i + j != n - 1){
                    if(mat[i][j] != 0) return false;
                }
            }
        }

        return true;
    }
};
