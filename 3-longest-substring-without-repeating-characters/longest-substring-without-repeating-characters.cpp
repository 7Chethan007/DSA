class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        set<char> set;
        int left = 0;

        for(int right = 0; right < n; right++){
            while(set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
        
        // vector<int> mpp(256,-1);
        // int left = 0, right = 0;
        // int len = 0;
        // int n = s.size();
        // while(right < n) {
        //     if (mpp[s[right]] != -1) left = max(mpp[s[right]] + 1, left);

        //     mpp[s[right]] = right;

        //     len = max(len, right - left + 1);
        //     right++;
        // }
        // return len;
    }
};