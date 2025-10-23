class Solution {
public:
     int maxSubArray(vector<int>& nums) {
          // maxSum stores the largest subarray sum found so far
          int maxSum = INT_MIN;
          // currentSum stores the sum of the subarray we are currently considering
          int currentSum = 0;

          for (int i = 0; i < (int)nums.size(); ++i) {
                currentSum += nums[i];         // extend the current subarray by nums[i]

                // update maxSum if the new currentSum is larger
                if (currentSum > maxSum) {
                     maxSum = currentSum;
                }

                // if currentSum is negative, it cannot help any future subarray,
                // so reset it to 0 to start a fresh subarray from the next element
                if (currentSum < 0) {
                     currentSum = 0;
                }
          }

          return maxSum;
     }
};