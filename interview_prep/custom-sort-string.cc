/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, 
if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

Example 1:

Input: order = "cba", s = "abcd"

Output: "cbad"

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "bcafg", s = "abcd"

Output: "bcad"
*/

class Solution {
public:
    string customSortString(string order, string s) {
        // put characters of s into a freq map
        unordered_map<int, int> m;
        for (char c : s) m[c] += 1; 

        // build the permutation
        string res;

        for (char c : order) {
            if (m.find(c) == m.end()) continue;

            while (m[c] > 0) {
                res += c;
                m[c] -= 1;
            }
        }

        // fill in the rest of characters
        for (auto entry : m) {
            while (entry.second > 0) {
                res += entry.first;
                entry.second -= 1;
            }
        }

        return res;
    }
};
