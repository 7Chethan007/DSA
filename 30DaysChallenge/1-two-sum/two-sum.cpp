class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> a;
        // a.reserve(n);
        for (int i = 0; i < n; ++i) a.emplace_back(nums[i], i);

        sort(a.begin(), a.end()); // sorts by value, but each pair keeps original index
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = a[l].first + a[r].first;
            if (sum == target) {
                return {a[l].second, a[r].second}; // original indices
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {};
    }
};
