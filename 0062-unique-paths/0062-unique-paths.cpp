vector<vector<int>> DP(101 , vector<int>(101,-1));
class Solution {
public:

    // applying Memoization since we have found overlapping nodes in recusrion tree
    int solve(int row, int col){

        if(row == 0 && col == 0) return 1;
        if(row<0 || col < 0) return 0;

        if(DP[row][col] != -1) return DP[row][col];

        int up = solve(row-1,col);
        int left = solve(row,col-1);

        DP[row][col] = up+left;
        return up+left; 
    }

    int uniquePaths(int m, int n) {
        
        return solve(m-1,n-1);
    }
};


// tc - o(m*n)
//sc - o(m-1 + n-1) + o(m*n)