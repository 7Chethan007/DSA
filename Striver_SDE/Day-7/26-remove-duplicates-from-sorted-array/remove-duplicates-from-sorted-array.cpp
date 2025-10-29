class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If array is empty, return 0 directly
        if (nums.empty()) return 0;
        int n = nums.size();
        int j = 1;
        for(int i = 1; i < n; i++) {
            // If current element is different from last unique element
            if(nums[i] != nums[j-1]) {
                // Place the new unique element at the next position
                nums[j] = nums[i];
                // Move pointer for unique element forward
                j++;
            }
        }
        // i is index of last unique element, count = i + 1
        return j;
    }



    // // Removes duplicates using unordered_set and returns count of unique elements
    // int removeDuplicates(vector<int>& nums) {
    //     // Unordered set to store elements we have already seen
    //     unordered_set<int> seen;

    //     // Index where the next unique element will be written
    //     int index = 0;

    //     // Loop over each element in the array
    //     for (int num : nums) {
    //         // If num is not in seen, it's unique
    //         if (seen.find(num) == seen.end()) {
    //             // Add this num to the set of seen numbers
    //             seen.insert(num);

    //             // Overwrite nums[index] with this unique num
    //             nums[index] = num;

    //             // Move index forward
    //             index++;
    //         }
    //     }
    //     // Return count of unique elements
    //     return index;
    // }
};