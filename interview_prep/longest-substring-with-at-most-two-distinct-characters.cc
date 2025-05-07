/*
Given a string s, return the length of the longest substring that contains at most two distinct characters.

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.

Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> distinct; // {char, count}
        int maxLength = INT_MIN;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            distinct[s[r]] += 1;
            if (distinct.size() > 2) {
                
                // move left pointer
                while (distinct.size() > 2) {
                    distinct[s[l]] -= 1;  
                    if (distinct[s[l]] == 0) distinct.erase(s[l]);
                    l += 1;
                } 

            } else {
                maxLength = max(maxLength, r - l + 1);
            }
        }

        return maxLength;
    }
};
