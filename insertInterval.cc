/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is 
sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals 
(merge overlapping intervals if necessary).

Return intervals after the insertion.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

*/

class Solution {
    bool inInterval(vector<int>& interval, int val) {
        if (interval[0] <= val && val <= interval[1]) return true;
        return false;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
    
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> result;

        int start = left;
        int end = right;

        int i = 0;

        while (i < len && left > intervals[i][1]) {
            result.push_back(intervals[i]);
            i++;
        }


        while (i < len && right >= intervals[i][0]) {
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
            i++;
        }

        result.push_back({start, end});

        while (i < len) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
