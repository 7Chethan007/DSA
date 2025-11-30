class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        //apply binary search:
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // cell is (i / m, i % m)(0-based indexing).
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    // bool binarySearch(vector<int>& nums, int target) {
    //     int n = nums.size(); //size of the array
    //     int low = 0, high = n - 1;

    //     // Perform the steps:
    //     while (low <= high) {
    //         int mid = (low + high) / 2;
    //         if (nums[mid] == target) return true;
    //         else if (target > nums[mid]) low = mid + 1;
    //         else high = mid - 1;
    //     }
    //     return false;
    // }
    //     // Row wise Binary Search
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     for (int i = 0; i < n; i++) {
    //         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
    //             return binarySearch(matrix[i], target);
    //         }
    //     }
    //     return false;
    // }
};