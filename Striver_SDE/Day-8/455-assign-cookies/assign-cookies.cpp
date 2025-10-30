class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0; // l for size r for greed

        while(l < m && r < n) {
            if(g[r] <= s[l]) { // if able to satisfy
                r += 1;         // go to next child
            }
            l += 1;  // if not able to satisfy go to next cookie
        }

        return r;
    }
};

// T : O(NlogN + MlogM + M{while loop})