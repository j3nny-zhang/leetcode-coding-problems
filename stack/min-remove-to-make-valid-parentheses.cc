/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string> st;
        int leftP = 0;

        for (char c : s) {
            if (c == '(') {
                leftP += 1;
                st.push(string{c});
                continue;
            }
            
            if (c != ')' || (c == ')' && leftP == 0)) {
                st.push(string{c});
                continue;
            }

            // c == ')' and enough left parenthesis
            string substring = "";
            string top = string{st.top()};
            while (!st.empty() && (st.top()[0] != '(' || st.top().length() != 1)) {
                substring = st.top() + substring;
                st.pop();
            }
            leftP -= 1;
            st.pop();

            st.push("(" + substring + ")");
        }

        string res = "";
        while (!st.empty()) {
            if ((st.top()[0] == '(' || st.top()[0] == ')') && st.top().length() == 1) {
                st.pop();
                continue;
            }
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
