/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) 
with the concatenation of the character and the number marking the count of the characters (length of the run). 
For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". 
Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
*/

class Solution {

public:
    string countAndSay(int n) {
        string res = "1";

        while (n > 1) {
            string temp = "";
            int size = res.size();
            for (int i = 0; i < size; i++) {
                    int n = res[i] - '0';
                    int count = 0;
                    int j = i;

                    while (res[j] - '0' == n) {
                        count += 1; 
                        j += 1;
                    }
                    
                    i = j - 1;
                    temp += (count + '0');
                    temp += (n + '0');
                }
                res = temp;
                n -= 1;
        }

        return res;
    }
};
