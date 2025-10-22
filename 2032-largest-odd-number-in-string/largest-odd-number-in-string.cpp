class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i = n - 1; i >= 0; i--) {
            if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }
        return "";


        // string res = "";
        // for (int i = 0; i < num.size(); i++) {
        //     int digit = num[i] - '0';
        //     if (digit % 2 != 0) {
        //         // Update result with current prefix up to this odd digit
        //         res = num.substr(0, i + 1);
        //     }
        // }
        // return res;
    }
};