class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                // Find an empty cell
                if (board[row][col] == '.') {

                    // Try digits 1 to 9
                    for (char digit = '1'; digit <= '9'; digit++) {

                        if (isValid(board, row, col, digit)) {

                            // Choose
                            board[row][col] = digit;

                            // Explore
                            if (solve(board)) {
                                return true;
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No valid digit found
                    return false;
                }
            }
        }

        // Board completely filled
        return true;
    }

    bool isValid(
        vector<vector<char>>& board,
        int row,
        int col,
        char digit
    ) {

        for (int i = 0; i < 9; i++) {

            // Row
            if (board[row][i] == digit) {
                return false;
            }

            // Column
            if (board[i][col] == digit) {
                return false;
            }

            // 3 × 3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == digit) {
                return false;
            }
        }

        return true;
    }
};