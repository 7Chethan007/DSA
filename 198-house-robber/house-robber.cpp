#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---- Space-Optimized DP version ----
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = nums[0];          // dp[i-1]
        int prev2 = 0;               // dp[i-2]

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2; // pick current + dp[i-2]
            int nonPick = prev;       // skip current => dp[i-1]
            int curr = max(pick, nonPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
