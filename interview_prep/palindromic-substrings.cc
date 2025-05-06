/*
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
*/

class Solution {
    void is_palindrome(int l,  int r, string &s, int &counter) {
    while (l >= 0 && r < s.length()) {
        if (s[l] != s[r]) {
            break;
        }
        l--;
        r++;
        counter++;
    }
}
public:
    int countSubstrings(string s) {
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            is_palindrome(i, i, s, counter);
            is_palindrome(i, i+1, s, counter);
        }
        return counter;
    }
};
