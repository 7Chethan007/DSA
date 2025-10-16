class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < n; i++) {
            // If bcz of maxIndex has not visited then i can't iterate
            // hence false
            if( i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
            // For optimisation or early stop
            // if we crossed the number of elements then definetely true
            if(maxIndex >= n) return true;
        }
        return true;
    }
};