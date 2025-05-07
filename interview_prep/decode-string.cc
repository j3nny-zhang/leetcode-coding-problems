/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. 
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.


Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/

class Solution {
    bool isNumber(string &s) {
        for (char ch : s) {
            if (!isdigit(ch)) return false;
        }
        return true;
    }
public:
    string decodeString(string s) {
        stack<string> st;
        string decode = "";
        int count = 0; // track closed (ie valid) parentheses
        int i = 0;

        while (i < s.size()) {
            char ch = s[i];
            if (isdigit(ch)) {
                string digit = "";

                // parse digits into a number
                while (isdigit(s[i])) {
                    digit += s[i++];
                }
                i -= 1;
                // --------------------------

                st.push(digit);
            } else if (ch == ']') {

                // closed parentheses
                string partiallyDecode = "";
                
                while (!isNumber(st.top()) && st.top() != "[") {
                    partiallyDecode = st.top() + partiallyDecode;
                    st.pop();
                }

                st.pop(); // pop "["

                // top contains the digit
                string repeated = "";
                for (int i = 0; i < stoi(st.top()); i++) {
                    repeated += partiallyDecode;
                }

                st.pop(); // pop the digit
                st.push(repeated);
                
            } else {
                st.push(string() + ch);
            }
            i += 1;
        }

        while (!st.empty()) {
            decode = st.top() + decode;
            st.pop();
        }

        return decode;
    }
};
