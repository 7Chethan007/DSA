#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // reverse the whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;        // write index
        int l = 0;        // read index

        while (l < n) {
            // skip any spaces
            while (l < n && s[l] == ' ') ++l;
            if (l >= n) break;

            // add a single space between words if this isn't the first word
            if (i != 0) s[i++] = ' ';

            // copy the next word to position i
            int r = l;
            while (r < n && s[r] != ' ')
                s[i++] = s[r++];

            // reverse that word in-place
            reverse(s.begin() + (i - (r - l)), s.begin() + i);

            // move l to r (next position to read)
            l = r;
        }

        // erase the leftover characters after the last write position
        s.erase(s.begin() + i, s.end());
        return s;
    }
};
