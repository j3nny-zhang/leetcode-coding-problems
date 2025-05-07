// LEETCODE'S SOLUTION

/*
Given a string s, return whether s is a valid number.

For example, all the following are valid numbers: 
"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", 
while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".

Formally, a valid number is defined using one of the following definitions:

An integer number followed by an optional exponent.
A decimal number followed by an optional exponent.
An integer number is defined with an optional sign '-' or '+' followed by digits.

A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:

Digits followed by a dot '.'.
Digits followed by a dot '.' followed by digits.
A dot '.' followed by digits.
An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.

The digits are defined as one or more digits.
*/

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (curr >= '0' && curr <= '9') {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};

// THIS IS THE DFA VERSION:

class Solution {
public:
    bool isNumber(string s) {
        // This is the DFA we have designed above
        map<string, int> dfa[8] = {{{"digit", 1}, {"sign", 2}, {"dot", 3}},
                                   {{"digit", 1}, {"dot", 4}, {"exponent", 5}},
                                   {{"digit", 1}, {"dot", 3}},
                                   {{"digit", 4}},
                                   {{"digit", 4}, {"exponent", 5}},
                                   {{"sign", 6}, {"digit", 7}},
                                   {{"digit", 7}},
                                   {{"digit", 7}}};
        int current_state = 0;
        string group;
        for (char c : s) {
            if (isdigit(c)) {
                group = "digit";
            } else if (c == '+' || c == '-') {
                group = "sign";
            } else if (c == 'e' || c == 'E') {
                group = "exponent";
            } else if (c == '.') {
                group = "dot";
            } else {
                return false;
            }
            if (dfa[current_state].find(group) == dfa[current_state].end()) {
                return false;
            }
            current_state = dfa[current_state][group];
        }
        return current_state == 1 || current_state == 4 || current_state == 7;
    }
};
