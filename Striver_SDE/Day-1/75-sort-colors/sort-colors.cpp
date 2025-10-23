class Solution {
public:
    void sortColors(vector<int>& nums) {
                        // Time O(n)+O(n) Space O(1)
        // int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == 0) cnt0++;
        //     if(nums[i] == 1) cnt1++;
        //     if(nums[i] == 2) cnt2++;
        // }

        //     //Replace the places in the original array:
        // for (int i = 0; i < cnt0; i++) nums[i] = 0; // replacing 0's
        // for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; // replacing 1's
        // for (int i = cnt0 + cnt1; i < nums.size(); i++) nums[i] = 2; // replacing 2's

        int n = nums.size();
        int low = 0, mid = 0, high = n - 1; // 3 pointers

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};