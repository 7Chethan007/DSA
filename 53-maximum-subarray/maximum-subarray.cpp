class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];             // Keep adding the elements
            if(sum > max) max = sum;    // if the sum becomes greater than max update it
            if(sum < 0) sum = 0;        // if sum goes below 0 i.e., -ve Reset it to be 0
        }
        return max;
    }
};