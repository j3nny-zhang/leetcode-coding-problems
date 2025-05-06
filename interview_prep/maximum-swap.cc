/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.


Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
*/

class Solution {
public:
    int maximumSwap(int num) {
        string strNum = to_string(num);
        vector<char> chNum;
        for (char c : strNum) chNum.push_back(c);

        char maxNum = '0';
        int max_i = chNum.size() - 1;
        int swap_i = chNum.size() - 1;
        int swap_j = chNum.size() - 1;

        for (int i = chNum.size() - 1; i >= 0; i--) {
            if (chNum[i] > maxNum) {
                max_i = i;
                maxNum = chNum[i];
            } else if (chNum[i] < maxNum) {
                swap_i = i;
                swap_j = max_i;
            }
        }

        swap(chNum[swap_i], chNum[swap_j]);
        string res = "";
        for (char c : chNum) res += c;

        return stoi(res);
    }
};
