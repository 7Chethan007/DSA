class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;

        // Initialize a 1D dp array with size m (columns)
        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0); // temp row for current computation
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                } else if (i == 0 && j == 0) {
                    temp[j] = 1; // Starting point
                } else {
                    int up = (i > 0) ? dp[j] : 0;
                    int left = (j > 0) ? temp[j - 1] : 0;
                    temp[j] = up + left;
                }
            }
            dp = temp; // move current row to dp (acts as previous in next iteration)
        }

        return dp[m - 1]; // bottom-right cell
    }
};
