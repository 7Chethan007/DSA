class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;

        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        string word = "";
        vector<string> words;

        // Step 2: Extract words
        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                word += ch;
            } else if (ch == ' ' && !word.empty()) {
                words.push_back(word);
                word = "";
            }
            left++;
        }
        // Add the last word
        if (!word.empty())
            words.push_back(word);

        // Step 3: Reverse order of words
        reverse(words.begin(), words.end());

        // Step 4: Join words with a single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};
