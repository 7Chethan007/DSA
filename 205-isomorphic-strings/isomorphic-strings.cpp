class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        char map_s[128] = {0}; // maps from s -> t
        char map_t[128] = {0}; // maps from t -> s

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (map_s[c1] == 0 && map_t[c2] == 0) {
                // first time mapping both characters
                map_s[c1] = c2;
                map_t[c2] = c1;
            } else {
                // check existing mapping
                if (map_s[c1] != c2 || map_t[c2] != c1) {
                    return false;
                }
            }
        }

        return true;
    }
};
