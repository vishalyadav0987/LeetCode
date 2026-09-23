class Solution {
public:
    // knight move (taking reference of image 
    // https://assets.leetcode.com/uploads/2018/10/12/knight.png)
    // 1. r-2,c-1
    // 2. r-2,c+1
    // 3. r-1,c+2
    // 4. r+1,c+2
    // 5. r+2,c+1
    // 6. r+2,c-1
    // 7. r+1,c-2
    // 8. r-1,c-2
    bool isVaildMove(vector<vector<int>>& grid,int r,int c,int expectedVal,int n){
        // base case
        if(r<0 || c <0 || r >=n || c >= n || grid[r][c] != expectedVal){
            return false;
        }
        if(expectedVal == n*n - 1){
            return true;
        }
        bool move1 = isVaildMove(grid,r-2,c-1, expectedVal+1,n);
        bool move2 = isVaildMove(grid,r-2,c+1, expectedVal+1,n);
        bool move3 = isVaildMove(grid,r-1,c+2, expectedVal+1,n);
        bool move4 = isVaildMove(grid,r+1,c+2, expectedVal+1,n);
        bool move5 = isVaildMove(grid,r+2,c+1, expectedVal+1,n);
        bool move6 = isVaildMove(grid,r+2,c-1, expectedVal+1,n);
        bool move7 = isVaildMove(grid,r+1,c-2, expectedVal+1,n);
        bool move8 = isVaildMove(grid,r-1,c-2, expectedVal+1,n);

        return move1 || move2 || move3 || move4 || move5 || move6 || move7 || move8; 
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isVaildMove(grid,0,0,0,grid[0].size());
    }
};