/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
**/

class Solution {
    void generateHelper(int l, int r, vector<string> &parentheses, string p) {
        if (l == 0 && r == 0) {
            parentheses.push_back(p);
            return;
        }

        if (l >= 0) { // backtracking step
            p += "(";
            generateHelper(l - 1, r, parentheses, p);
            p.pop_back();
        } 

        if (r >= 0 && l < r) { // only generate right parenthesis if there are enough left parentheses already generated
            p += ")";
            generateHelper(l, r - 1, parentheses, p);
        }

    }

public:
    vector<string> generateParenthesis(int n) {
        // keep track of remaining left and right parentheses
        int l = n;
        int r = n;

        vector<string> parentheses;

        generateHelper(l, r, parentheses, "");

        return parentheses;
    }
};
