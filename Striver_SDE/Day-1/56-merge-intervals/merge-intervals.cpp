class Solution {
public:
    // T : O(N*logN) + O(N^2) S: O(N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        // Vector to store final merged intervals
        vector<vector<int>> merged;

        // Traverse each interval
        for (auto interval : intervals) {
            // If merged is empty or current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // Add current interval as a new non-overlapping block
                merged.push_back(interval);
            } else {
                // Overlapping: merge by extending the end time
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }

        return merged;
    }

    // T : O(N^2) S: O(N)
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     // Sort intervals based on start time
    //     sort(intervals.begin(), intervals.end());
    //     // Result array to store merged intervals
    //     vector<vector<int>> ans;
    //     // Loop through each interval
    //     int n = intervals.size();
    //     for (int i = 0; i < n; ) {
    //         // Start of current merged interval
    //         int start = intervals[i][0];
    //         int end = intervals[i][1];

    //         // Merge with all overlapping intervals
    //         int j = i + 1;
    //         while (j < n && intervals[j][0] <= end) {
    //             // Update end to the maximum of current end and overlapping interval's end
    //             end = max(end, intervals[j][1]);
    //             j++;
    //         }
    //         // Add the merged interval to result
    //         ans.push_back({start, end});
    //         // Move to the next non-overlapping interval
    //         i = j;
    //     }
    //     return ans;
    // }
};