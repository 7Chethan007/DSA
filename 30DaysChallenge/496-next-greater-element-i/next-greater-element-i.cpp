class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        vector<int> res(nums1.size(),-1);
        
        for(int num : nums2) {
            while(!st.empty() && num > st.top()) {
                map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()) {
            map[st.top()] = -1;
            st.pop();
        }
        for(int i = 0; i < nums1.size(); i++) {
            res[i] = map[nums1[i]];
        }
        
        return res;

        // for(int i = 0; i < n; i++) {

        //     for(int j = 0; j < nums2.size(); j++) {
        //         if(nums1[i] == nums2[j]) {
        //             for(int k = j; k < nums2.size();k++) {
        //                 if(nums2[k] > nums2[j]) {
        //                     res[i] = nums2[k];
        //                     break;
        //                 }
        //             }
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};