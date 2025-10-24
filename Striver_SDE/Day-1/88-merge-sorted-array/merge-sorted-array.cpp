class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // i points to last valid element in nums1
        int j = n - 1;      // j points to last element in nums2
        int k = m + n - 1;  // k is the last index of nums1 (including 0 placeholders)

        // Merge in reverse to avoid overwriting elements in nums1
        // Start by putting the larger element from the end of nums1
        while (i >= 0 && j >= 0) {
            // Place larger of the two at nums1[k]
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements left in nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};