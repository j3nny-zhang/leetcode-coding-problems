/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

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
public:
    string decodeString(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
                continue;
            }

            string substring = "";
            while (st.top() != '[') {
                substring = st.top() + substring;
                st.pop();
            }

            // now top is [ character
            st.pop();

            // now top is a number, may be more than one digit
            string num = "";
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }

            int rep = stoi(num);

            string ss = "";
            // repeat substring rep times
            for (int j = 0; j < rep; j++) {
                ss += substring;
            }
            
            // now put all the chars in ss back into the stack
            for (char c : ss) {
                st.push(c);
            }

        }
        
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
