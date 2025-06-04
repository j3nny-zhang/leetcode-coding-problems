/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";


        unordered_map<int, int> freq; // freq count
        for (char ch : t) freq[ch] += 1;
        int minLen = INT_MAX;
        int startIndex = 0;

        int count = freq.size(); // letters needed in the substring
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            freq[s[r]] -= 1;
            if (freq[s[r]] == 0) count -= 1;

            while (count == 0) {
                if (r - l + 1 < minLen) {
                    startIndex = l;
                    minLen = r - l + 1;
                }
                
                freq[s[l]] += 1;
                if (freq[s[l]] > 0) count += 1;
                l += 1;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
