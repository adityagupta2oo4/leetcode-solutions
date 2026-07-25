class Solution {
public:

    // applying Memoization since we have found overlapping nodes in recusrion tree
    int solve(int row, int col,vector<vector<int>> &DP){

        if(row == 0 && col == 0) return 1;
        if(row<0 || col < 0) return 0;

        if(DP[row][col] != -1) return DP[row][col];

        int up = solve(row-1,col,DP);
        int left = solve(row,col-1,DP);

        DP[row][col] = up+left;
        return up+left; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m , vector<int>(n,-1));
        return solve(m-1,n-1,DP);
    }
};


// tc - o(m*n)
//sc - o(m-1 + n-1) + o(m*n)