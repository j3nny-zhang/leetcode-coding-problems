/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
 
Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

class Solution {
    int perform(int x, int y, char op) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> res;
        bool isNumber = true;

        // depth first
        for (int i = 0; i < expression.length(); i++) {
            // is operator
            if (!isdigit(expression[i])) {
                // still an expression
                isNumber = false;

                // split into left and right expression substrees
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for (int x : left) {
                    for (int y : right) {
                        int val = perform(x, y, expression[i]);
                        res.push_back(val);
                    }
                }
            }
        }
        if (isNumber) res.push_back(stoi(expression));
        return res;
    }
};
