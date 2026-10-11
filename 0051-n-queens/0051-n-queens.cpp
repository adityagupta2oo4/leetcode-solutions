
class Solution {
public:
    vector<vector<string>> solutions;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check the same column in previous rows
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        // All queens have been placed
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        // Try placing a queen in every column
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(board, row + 1, n);

                // Undo (backtrack)
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        solutions.clear();

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return solutions;
    }
};
