class Solution {
public:
    int reverse(int x) {
        long long ans = 0; // Use long long to detect overflow
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            ans = ans * 10 + digit;

            if (ans > INT_MAX || ans < INT_MIN)
                return 0; // Overflow detected
        }
        return static_cast<int>(ans); // Safe cast since overflow is checked
    }
};
