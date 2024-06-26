/**
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.


Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
**/

// i feel like there's a more efficient solution :(

class Solution {
    bool checkPerm(string s2, int l, int r, unordered_map<char, int> perm) {
        for (int i = l; i <= r; i++) {
            perm[s2[i]] -= 1;
        }

        for (auto entry : perm) {
            if (entry.second != 0) return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> perm;

        if (s1.size() > s2.size()) return false;

        for (char c : s1) {
            perm[c] += 1;
        }

        int length = s1.size() - 1;
        int r = length;

        while (r < s2.size()) {
            if (perm.contains(s2[r])) {
                bool isPerm = checkPerm(s2, r - length, r, perm);
                if (isPerm) return true;
            }

            r += 1;
        }

        return false;
    }
};
