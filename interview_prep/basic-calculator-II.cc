/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int prev = 0; 
        int curr = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]) && !iswspace(s[i])) { // number
                
                // convert into integer
                string n = "";
                while (isdigit(s[i]) && !iswspace(s[i])) {
                    n += s[i++];
                }
                i -= 1;
                curr = stoi(n);
                // 

                if (sign == '+' || sign == '-') {
                    result += prev;
                    prev = (sign == '+') ? curr : -curr;
                    
                } else { // * or /
                    if (sign == '*') {
                        prev = prev * curr;
                    } else {
                        prev = prev / curr;
                    }
                }

            } else if (!iswspace(s[i])) { // operation
                sign = s[i];
            }
        }
        
        result += prev;
        return result;
    }
};
