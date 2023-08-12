/*
You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, 
so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. 
If the given string is not a combination of a valid "croak" return -1.
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        int result = 0;

        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                c++;
            } else if (ch == 'r') {
                if (++r > c) return -1;
            } else if (ch == 'o') {
                if (++o > r) return -1;
            } else if (ch == 'a') {
                if (++a > o) return -1;
            } else {
                if (++k > a) return -1;
                result = max(result, c - k + 1); // this deals with a frog croaking in sequence
            }
        }

        if (c != r || r != o || o != a || a != k || k != c) return -1;

        return result;
    }
};
