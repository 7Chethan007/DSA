class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector <int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            // Condition to remove the last of the sliding window
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();

            // To maintain the decending order value graph
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            //  To take in at the face or start of window where it's updating everytime
            dq.push_back(i);
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};