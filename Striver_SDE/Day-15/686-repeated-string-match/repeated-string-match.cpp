class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1;
        string temp = A;

        // Keep appending A until temp is at least as long as B
        while (temp.length() < B.length()) {
            temp += A;
            count++;
        }

        // Check if B is now a substring of temp
        if (temp.find(B) != string::npos)
            return count;

        // One more repetition may be needed
        temp += A;
        if (temp.find(B) != string::npos)
            return count + 1;

        // Not found
        return -1;
    }
};
