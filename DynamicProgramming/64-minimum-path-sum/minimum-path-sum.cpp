class Solution {
public:
    // Function to calculate minimum path sum with memoization
    int minPath(int i, int j,
                vector<vector<int>> &grid,
                vector<vector<int>> &dp) {
        // If we are at (0,0), return that cell's value
        if (i == 0 && j == 0)
            return grid[0][0];

        // If out of bounds, return large number
        if (i < 0 || j < 0)
            return 1e9;

        // If already computed, return from dp
        if (dp[i][j] != -1)
            return dp[i][j];

        // Compute path by going up
        int up = grid[i][j] +
                 minPath(i - 1, j, grid, dp);

        // Compute path by going left
        int left = grid[i][j] +
                   minPath(i, j - 1, grid, dp);

        // Store the minimum in dp and return
        return dp[i][j] = min(up, left);
    }

    // Main function that initializes dp and calls helper
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create dp table initialized with -1
        vector<vector<int>> dp(n,
                vector<int>(m, -1));

        // Start from bottom-right corner
        return minPath(n - 1, m - 1, grid, dp);
    }
};
