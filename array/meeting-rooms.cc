/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end());

        if (intervals.size() == 0) return true;

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) return false;
            end = intervals[i][1];
        }

        return true;
    }
};
