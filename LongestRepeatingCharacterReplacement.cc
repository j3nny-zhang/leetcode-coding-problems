/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

class Solution {
    unordered_map<char, int> m; // {char, count}
    
    bool moreThanK(int k, int length) {
        int maximum = 0;
        for (auto entry : m) {
            maximum = max(entry.second, maximum);
        }

        return (length - maximum  > k);
    }

public:
    int characterReplacement(string s, int k) {
        int i = 0; int j = 0;
        int result = 0;

        while (j < s.length()) {
            m[s[j]] += 1;

            if (moreThanK(k, j-i+1)) {
                m[s[i]] -= 1;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }
};
