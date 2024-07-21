/*
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. 
If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.

Example 2:
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".

Example 3:
Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> indices(26, -1);
        int length = -1;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (indices[idx] != -1) {
                length = max(length, i - indices[idx] - 1);
            } else {
                indices[idx] = i;
            }
        }

        return length;
    }
};
