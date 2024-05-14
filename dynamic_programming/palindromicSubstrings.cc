/**
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
**/

class Solution {
    void checkPalindrome(int l, int r, int &res, string &s) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res += 1;
            l -= 1;
            r += 1;
        }
    }

public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            checkPalindrome(i, i, res, s);
            checkPalindrome(i, i+1, res, s);
        }
        return res;
    }
};
