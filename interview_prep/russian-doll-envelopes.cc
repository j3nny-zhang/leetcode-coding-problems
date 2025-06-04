/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/

class Solution {
    // sort width in increasing order
    // if widths are equal, sort height in decreasing order
    static bool compare (vector<int>&a, vector<int>&b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> res; // vector of widths

        res.push_back(envelopes[0][1]);

        for (vector<int>& envelope : envelopes) {
            if (envelope[1] > res.back()) {
                res.push_back(envelope[1]);
            } else {
                int i = lower_bound(res.begin(), res.end(), envelope[1]) - res.begin();
                res[i] = envelope[1];
            }
        }

        return res.size();
    }
};
