/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

class Solution {
    vector<string> getWords(int i, vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        int currLength = 0;

        while (i < words.size() && currLength + words[i].size() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].size() + 1;
            i++;
        }
        return currentLine;
    }

    string createLine(vector<string>& line, int i, vector<string>& words, int maxWidth) {
        int baseLength = -1;
        for (const string& word : line) baseLength += word.size() + 1;
        int extraSpaces = maxWidth - baseLength;
        
        if (line.size() == 1 || i == words.size()) {
            string res = join(line, " ");
            res += string(extraSpaces, ' ');
            return res;
        }

        int wordCount = line.size() - 1;
        int spacesPerWord = extraSpaces / wordCount;
        int needsExtraSpace = extraSpaces % wordCount;
        for (int j = 0; j < needsExtraSpace; j++) {
            line[j] += " ";
        }
        for (int j = 0; j < wordCount; j++) {
            line[j] += string(spacesPerWord, ' ');
        }

        return join(line, " ");
    }

    string join(vector<string>& line, const string& delimeter) {
        if (line.empty()) return "";

        string res(line[0]);
        for (int i = 1; i < line.size(); i++) {
            res += delimeter + line[i];
        }

        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            vector<string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words, maxWidth));
        }
        return ans;
    }
};
