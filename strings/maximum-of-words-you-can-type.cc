/*
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct 
letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char c : brokenLetters) broken.insert(c);

        int numOfBroken = 0;

        stringstream ss{text};
        vector<string> words;
        string word;

        while(getline(ss, word, ' ')) words.push_back(word);

        for (string& w : words) {
            bool found = false;
            for (char c : w) {
                if (broken.find(c) != broken.end()) {
                    found = true;
                }
            }
            if (found) numOfBroken += 1;
        }

        return words.size() - numOfBroken;
    }
};
