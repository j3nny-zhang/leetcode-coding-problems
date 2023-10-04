/*
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.


Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
*/

class Solution {
    static bool cmp(string &a, string &b) {
        int i1 = a.find(' ');
        int i2 = b.find(' ');
        string sub1 = a.substr(i1+1);
        string sub2 = b.substr(i2+1);

        if (sub1 == sub2) return a < b;
        return sub1 < sub2;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        vector<string> digitLogs;
        vector<string> result;

        for (string &log : logs) {
            int index = log.find(' ');
            if (log[index + 1] >= 'a' && log[index + 1] <= 'z') { // is a letterLog
                letterLogs.push_back(log);
            } else { 
                // erase delimiter
                digitLogs.push_back(log);
            }
        }
        sort(letterLogs.begin(), letterLogs.end(), cmp);
        for (string log : letterLogs) {
            result.push_back(log);
        }
        for (string log : digitLogs) {
            result.push_back(log);
        }

        return result;
    }
};
