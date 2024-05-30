/**
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
**/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str;
        stringstream ss(s);

        while (getline(ss, str, ' ')) {
            string temp = "";
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == ' ') continue;
                temp += str[i];
            }
            if (temp.size() != 0) st.push(temp);
        }

        string result = "";
        while (st.size() > 1) {
            result += st.top();
            st.pop();
            result += " ";
        }

        result += st.top();

        return result;
    }
};
