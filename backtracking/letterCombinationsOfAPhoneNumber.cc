/**
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
  Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
**/

class Solution {
    void combination(int i, string comb, vector<string> &result, string digits, unordered_map<char, string> &m) {
        if (i == digits.size()) {
            result.push_back(comb);
            return;
        }

        string letters = m[digits[i]];
        for (char letter: letters) {
            combination(i+1, comb + letter, result, digits, m);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        
        unordered_map<char, string> m = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };

        vector<string> result;
        combination(0, "", result, digits, m);

        return result;
    }
};
