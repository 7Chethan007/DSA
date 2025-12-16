class Solution {
public:
    bool isdigit(char c) { return c >= '0' && c <= '9'; }
    
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ')
            i++; // Step 1: Skip leading whitespace

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) { // Step 2: Check sign
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
        while (i < n && isdigit(s[i])) { // Step 3: Read digits
            result = result * 10 + (s[i] - '0');

            // Step 4: Clamp if out of bounds
            if (sign * result >= INT_MAX)
                return INT_MAX;
            if (sign * result <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return static_cast<int>(sign * result);
        // result is long, Function must return int
        // Overflow beign handled → safe to cast
    }
};