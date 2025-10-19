class Solution {
public:
    int minPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Create DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // First cell initialization
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    // Calculate from top
                    int up = matrix[i][j];
                    if (i > 0) up += dp[i - 1][j];
                    else up += 1e9;

                    // Calculate from left
                    int left = matrix[i][j];
                    if (j > 0) left += dp[i][j - 1];
                    else left += 1e9;

                    // Take minimum
                    dp[i][j] = min(up, left);
                }
            }
        }

        // Return result
        return dp[n - 1][m - 1];
    }

};