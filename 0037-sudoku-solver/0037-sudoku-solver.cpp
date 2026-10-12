
class Solution {
public:
    bool isSafe(vector<vector<char>>& board,
                int row, int col, char num) {

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num)
                return false;
        }

        // Check 3x3 sub-box
        int row_start = (row / 3) * 3;
        int col_start = (col / 3) * 3;

        for (int i = row_start; i < row_start + 3; i++) {
            for (int j = col_start; j < col_start + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        // Entire board completed
        if (row == 9)
            return true;

        // Move to the next row
        if (col == 9)
            return solve(board, row + 1, 0);

        // Skip already-filled cells
        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }

        // Try digits 1 through 9
        for (char num = '1'; num <= '9'; num++) {

            if (isSafe(board, row, col, num)) {

                board[row][col] = num;

                if (solve(board, row, col + 1))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
