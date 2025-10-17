class Solution {
public:
    // Helper function to solve the linear House Robber problem
    long long solve(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        long long prev = arr[0]; // dp[i-1]
        long long prev2 = 0;     // dp[i-2]

        for (int i = 1; i < n; i++) {
            long long pick = arr[i];
            if (i > 1) pick += prev2;
            long long nonPick = prev;

            long long curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> arr1, arr2;

        // arr1 = skip first house, arr2 = skip last house
        for (int i = 0; i < n; i++) {
            if (i != 0) arr1.push_back(nums[i]);
            if (i != n - 1) arr2.push_back(nums[i]);
        }

        long long ans1 = solve(arr1);
        long long ans2 = solve(arr2);

        return (int)max(ans1, ans2);
    }
};
