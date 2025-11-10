class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                if (st.empty() || st.top() != c) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
        
        // for (char c : s) {
        //     // Push opening brackets onto stack
        //     if (c == '(' || c == '{' || c == '[') {
        //         st.push(c);
        //     }
        //     // Check for closing brackets
        //     else {
        //         if (st.empty()) return false; // no opening bracket to match
                
        //         char top = st.top();
        //         st.pop();
                
        //         if ((c == ')' && top != '(') ||
        //             (c == '}' && top != '{') ||
        //             (c == ']' && top != '[')) {
        //             return false;
        //         }
        //     }
        // }
        
        // return st.empty(); // valid only if no unmatched brackets remain
    }
};