class Solution {
public:
    int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 || j < 0) return 0; // If we go out of bounds, return 0
        if (maze[i][j] == 1) return 0; // If there's an obstacle at (i, j), return 0
        if (i == 0 && j == 0) return 1; // If we reach the destination (0, 0), return 1
        if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it

        // Recursive calls to explore paths from (i, j) to (0, 0)
        int up = mazeObstaclesUtil(i - 1, j, maze, dp);
        int left = mazeObstaclesUtil(i, j - 1, maze, dp);

        // Store the result in the DP table and return it
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // Edge case: start or end is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
        return mazeObstaclesUtil(n - 1, m - 1, obstacleGrid, dp); // Start from the bottom-right corner
    }
};

