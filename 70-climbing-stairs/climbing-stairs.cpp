class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int prev2 = 1;
        int prev = 1;
        for (int i = 2; i <= n; i++) {
            // dp[i] = dp[i - 1] + dp[i - 2];
            int curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
        }

        // return dp[n];
        return prev;
    }
};
