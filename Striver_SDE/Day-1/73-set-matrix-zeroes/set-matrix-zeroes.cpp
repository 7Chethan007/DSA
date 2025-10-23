#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns
        int col0 = 1;                 // flag to track if the first column should be zero

        // -------------------------------
        // Step 1: Mark the first row and first column
        // -------------------------------
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == 0) {
                    // Mark the start of the current row
                    matrix[row][0] = 0;

                    // Mark the start of the current column
                    if (col != 0)
                        matrix[0][col] = 0;
                    else
                        col0 = 0; // special case for first column
                }
            }
        }

        // -------------------------------
        // Step 2: Use the markers in first row & column
        // to set other cells to 0 Excluding 0th row & column
        // -------------------------------
        for (int row = 1; row < n; row++) {
            for (int col = 1; col < m; col++) {
                if (matrix[row][col] != 0) {
                    if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                        matrix[row][col] = 0;
                    }
                }
            }
        }

        // -------------------------------
        // Step 3: Handle the first row and first column
        // -------------------------------
        // If the top-left cell is 0, set the entire first row to 0
        if (matrix[0][0] == 0) {
            for (int col = 0; col < m; col++) {
                matrix[0][col] = 0;
            }
        }
        // If col0 flag is 0, set the entire first column to 0
        if (col0 == 0) {
            for (int row = 0; row < n; row++) {
                matrix[row][0] = 0;
            }
        }
    }
};
