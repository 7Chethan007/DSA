class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxCnt = INT_MIN;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1){
                cnt++;
            }
            else {
                cnt = 0;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};