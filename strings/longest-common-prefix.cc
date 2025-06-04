/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string prefix = "";
        char curr = strs[0][0];

        while (true) {
            for (string& st : strs) {
                if (index >= st.size()) return prefix;
                if (st[index] !=  curr) return prefix;
            }

            index += 1;
            prefix += curr;
            curr = strs[0][index];
        }

        return prefix;
    }
};
