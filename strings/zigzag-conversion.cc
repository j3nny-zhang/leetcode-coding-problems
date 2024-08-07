/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.length();
        vector<string> v(numRows);

        int row = 0;
        bool rowDir = true;
        int diag = numRows - 2;

        for (int i = 0; i < n; i++) {
            if (row == numRows) {
                v[diag] += s[i];
                diag -= 1;
                if (diag <= 0) {
                    diag = numRows - 2;
                    if (numRows == 2) row = 1; // weird base case thingy
                    else row = 0;
                }
            } else {
                v[row] += s[i];
                row += 1;
            }
        }

        string res = "";
        for (string st : v) {
            res += st;
            //cout << st << endl;
        }

        return res;
    }
};
