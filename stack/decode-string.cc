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
        stack<string> sk;
        string decode;
        string digit = ""; // if we are reading in a digit - only relevant for first if statement
        
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ']') {
                while (true) {
                    string top = sk.top();
                    sk.pop();
                    if (top == "[") {
                        break;
                    }
                    decode = top + decode;
                }

                // there is now a number / numbers
                string digit;
                while (true) {
                    if (sk.empty()) break;
                    char d = sk.top()[0];
                    if (!isdigit(d)) break;
                    digit = d + digit;
                    sk.pop();
                }
                int num = stoi(digit);
                string toDuplicate = decode;
                while (num - 1 > 0) {
                    decode += toDuplicate;
                    num -= 1;
                }
                sk.push(decode);
                decode = "";
            } else {
                string ch = "";
                ch += s[i];
                sk.push(ch);
            }
        }

        while (!sk.empty()) {
            decode = sk.top() + decode;
            sk.pop();
        }
        return decode;
    }
};
