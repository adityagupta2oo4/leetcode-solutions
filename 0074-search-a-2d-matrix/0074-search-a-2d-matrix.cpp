class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // get the target row

        int row = matrix.size();
        int col = matrix[0].size();

        int target_row =  -1;
        for(int i = 0 ; i<row ; i++ ){

            if(matrix[i][0] <= target && target <= matrix[i][col-1]) {
                target_row = i;
                break;
            }
        }

        // before searching is a valid row was found?

        if(target_row == -1) return false;

        // searching the target in the target row

        for(int j = 0 ; j < col ; j++){

            if(matrix[target_row][j] == target){
                return true;
            }

        }

        return false;
        
    }
};