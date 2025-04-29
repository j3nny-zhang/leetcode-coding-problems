/*
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. 
  The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        vector<string> tokens;

        // parse abbr string and convert into tokens of chars and numbers
        for (int i = 0; i < abbr.size(); i++) {
            if (isdigit(abbr[i])) {
                if (abbr[i] == '0') return false; // edge case, leading 0
                string number = "";
                while (isdigit(abbr[i])) {
                    number += abbr[i++];
                }
                i -= 1;
                tokens.push_back(number);
            } else {
                string str(1, abbr[i]);
                tokens.push_back(str); // turns char into string of length 1
            }
        }

        int index = 0; // keeps track of position in "word"
        int n; 

        // check if valid abbr
        for (string &t : tokens) {
            stringstream ss{t};
            if (ss >> n) { // is a digit
                index += n;
                continue;
            }

            // convert char into string
            string comp = "";
            comp += word[index];

            if (t != comp) return false;
            index += 1;
        }

        if (index != word.size()) return false;
        return true;
    }
};
