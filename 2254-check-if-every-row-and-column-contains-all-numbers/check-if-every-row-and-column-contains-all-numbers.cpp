class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // horizontal
        int n = matrix[0].size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=0;j<n;j++){
                if(matrix[i][j] > n || matrix[i][j] < 1) return false;
                if(st.count(matrix[i][j])) return false;
                st.insert(matrix[i][j]);
            }
        }

        // verical case
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=0;j<n;j++){
                if(matrix[j][i] > n || matrix[j][i] < 1) return false;
                if(st.count(matrix[j][i])) return false;
                st.insert(matrix[j][i]);
            }
        }

        return true;
    }
};