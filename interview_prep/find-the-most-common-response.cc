/*
You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.

Return the most common response across all days after removing duplicate responses within each responses[i]. 
If there is a tie, return the lexicographically smallest response.

Example 1:

Input: responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]

Output: "good"

Explanation:

After removing duplicates within each list, responses = [["good", "ok"], ["ok", "bad", "good"], ["good"], ["bad"]].
"good" appears 3 times, "ok" appears 2 times, and "bad" appears 2 times.
Return "good" because it has the highest frequency.

Example 2:

Input: responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]

Output: "bad"

Explanation:

After removing duplicates within each list we have responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"], ["great", "good"]].
"bad", "good", and "ok" each occur 2 times.
The output is "bad" because it is the lexicographically smallest amongst the words with the highest frequency.
*/

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<int, unordered_set<string>> m; // {index, strings}

        for (int i = 0; i < responses.size(); i++) {
            for (int j = 0; j < responses[i].size(); j++) {
                m[i].insert(responses[i][j]);
            }
        }

        unordered_map<string, int> freq; // {string, count}

        for (auto &[i, set] : m) {
            for (auto &string : set) {
                freq[string] += 1;
            }
        }

        string res = "zzzzzzzzzz";
        int maxCount = INT_MIN;
        for (auto &[word, count] : freq) {
            if (count > maxCount) {
                res = word;
                maxCount = count;
            } else if (count == maxCount) {
                res = min(word, res);
            }
        }

        return res;
    }
};
