/*
Given an array of distinct strings words, return the minimal possible abbreviations for every word.

The following are the rules for a string abbreviation:

The initial abbreviation for each word is: the first character, then the number of characters in between, followed by the last character.
If more than one word shares the same abbreviation, then perform the following operation:
Increase the prefix (characters in the first part) of each of their abbreviations by 1.
For example, say you start with the words ["abcdef","abndef"] both initially abbreviated as "a4f". 
Then, a sequence of operations would be ["a4f","a4f"] -> ["ab3f","ab3f"] -> ["abc2f","abn2f"].
This operation is repeated until every abbreviation is unique.
At the end, if an abbreviation did not make a word shorter, then keep it as the original word.
 

Example 1:

Input: words = ["like","god","internal","me","internet","interval","intension","face","intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Example 2:

Input: words = ["aa","aaa"]
Output: ["aa","aaa"]
*/

class Solution {
    string abbreviate(string& word) {
        if (word.size() <= 3) return word;

        return word[0] + to_string(word.length() - 2) + word.back();
    }

    int LCP(string& a, string& b) {
        if (a.length() != b.length()) return 0;
        int i = 0;
        for (; i < a.length(); i++) {
            if (a[i] != b[i]) return i;
        }
        return i;
    }
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<int>> abbreviations; // {string, [list of indices]}
        vector<string> res(words.size());

        for (int i = 0; i < words.size(); i++) {
            string abbrev = abbreviate(words[i]);
            abbreviations[abbrev].push_back(i);
            res[i] = abbrev;
        }

        for (auto& [word, indices] : abbreviations) {
            if (indices.size() < 2) continue;
            int len = indices.size();

            vector<int> dp(len, 0);
            for (int i = 0; i < len; i++) {
                string &curr = words[indices[i]];
                for (int j = i+1; j < len; j++) {
                    int sumOfLCP = LCP(curr, words[indices[j]]);
                    if (sumOfLCP > dp[i]) dp[i] = sumOfLCP;
                    if (sumOfLCP > dp[j]) dp[j] = sumOfLCP;
                }
                if (dp[i] >= curr.size() - 3) {
                    res[indices[i]] = curr;
                } else {
                    string left = curr.substr(dp[i]);
                    res[indices[i]] = curr.substr(0, dp[i]) + abbreviate(left);
                }
            }
        }
        return res;
    }
};
