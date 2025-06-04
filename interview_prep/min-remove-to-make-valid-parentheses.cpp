/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> res1;
        int counter = 0; // keep track of balanced open / closed parentheses

        // first pass removes extra ) parentheses
        for (char c : s) {
            if (c == '(') {
                counter += 1;
                res1.push_back(c);
            } else if (c == ')' && counter > 0) {
                counter -= 1;
                res1.push_back(c);
            } else if (c != ')') {
                res1.push_back(c);
            }
        }

        vector<char> res2;
        // second pass removes extra ( parentheses
        for (int i = res1.size() - 1; i >= 0; i--) {
            if (res1[i] == '(' && counter > 0) {
                counter -= 1;
            } else {
                res2.push_back(res1[i]);
            }
        }

        // turn into string
        string valid = "";
        for (int i = res2.size() - 1; i >= 0; i--) {
            valid += res2[i];
        }

        return valid;
    }
};
