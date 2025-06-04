/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

class Solution {
    bool helper(string s, bool left) {
        int l = 0;
        int r = s.size() - 1;

        bool oneMistake = false;
        while (l <= r) {
            if (!oneMistake && s[l] != s[r]) {
                if (left) {
                    l += 1;
                } else {
                    r -= 1;
                }
                oneMistake = true;
                continue;
            } else if (oneMistake && s[l] != s[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }

        return true;
    }
public:
    bool validPalindrome(string s) {
        bool removeFromLeft = helper(s, true);
        bool removeFromRight = helper(s, false);
        return (removeFromLeft || removeFromRight);
    }
};



// SOLUTION 2
class Solution {
    bool helper(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return (helper(s, l, r - 1) || helper(s, l + 1, r));
            }
            l += 1;
            r -= 1;
        }

        return true;
    }
};
