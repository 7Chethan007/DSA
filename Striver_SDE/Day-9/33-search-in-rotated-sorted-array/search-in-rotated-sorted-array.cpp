class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            // Base Case
            if(nums[mid] == target) return mid;

            // left half is sorted
            if(nums[low] <= nums[mid]) {
                // Checking if target is in this left sorted half
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else { // if not in the sorted half
                    low = mid + 1;
                }
            }

            // right half is sorted
            if(nums[mid] <= nums[high]) {
                // Checking if target is in this sorted part
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};