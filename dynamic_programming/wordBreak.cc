/**
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
**/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // put strings in wordDict into set for O(1) retreival time
        unordered_set<string> dict;
        for (string &word : wordDict) {
            dict.insert(word);
        }

        int n = s.size();

        // let dp[i] = true if s can be segmented into sequence of strings for first i characters
        vector<bool> dp(n+1, false);
        dp[0] = true; // empty string returns true

        for (int i = 1; i < n + 1; i++) {
            for (int k = 0; k < i; k++) {
                dp[i] = dp[k] && (dict.contains(s.substr(k, i - k)));
                if (dp[i]) break;
            }
        }

        return dp[n];
    }
};
