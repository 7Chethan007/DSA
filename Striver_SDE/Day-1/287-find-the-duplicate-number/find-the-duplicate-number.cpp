class Solution {
public:
    int findDuplicate(vector < int > & nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
    // // Using O(N) Space
    // int findDuplicate(vector < int > & arr) {
    //     int n = arr.size();
    //     vector<int> freq(n + 1, 0);
    //     for (int i = 0; i < n; i++) {
    //         if (freq[arr[i]] == 0) {
    //             freq[arr[i]] += 1;
    //         } else {
    //             return arr[i];
    //         }
    //     }
    //     return 0;
    // }
};