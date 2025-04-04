/**
Example 1:

Input: s = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.
Example 2:

Input: s = "aaaaaaaaaa"
Output: 55
**/

class Solution {
public:
    int countLetters(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            ans += (1 + j - i) * (j - i) / 2;
            i = j;
        }
        return ans;
    }
};
