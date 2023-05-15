/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;

        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                p.push(c);
            } 

            if (c == '}' || c == ']' || c == ')') {
                if (p.size() == 0) return false;
                if (c == '}' && p.top() != '{') return false;
                if (c == ']' && p.top() != '[') return false;
                if (c == ')' && p.top() != '(') return false;
                
                p.pop();
                
            }
        }

        if (p.size() != 0) return false;

        return true;
    }
};
