/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make 
the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

class Solution {
 
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int counter = 0;
        if (intervals.size() == 0 || intervals.size() == 1) return 0;

        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (r > intervals[i][0]){ 
                counter += 1;
                r = min(r, intervals[i][1]);
            } else {
                r = intervals[i][1];
            }
            
        }

        return counter;
    }
};
