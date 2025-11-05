#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        // Iterate from right to left
        for (int i = s.size() - 1; i >= 0; --i) {
            int value = romanMap[s[i]];
            if (value < prevValue)
                total -= value;
            else
                total += value;
            prevValue = value;
        }

        return total;
    }
};
