class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Approach:
        // Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
        // Step 2: Reverse each row of the matrix.
        int size  = matrix.size();
        // Transpose : Make row to col & col to row
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < row; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row of the matrix
        for (int row = 0; row < size; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};