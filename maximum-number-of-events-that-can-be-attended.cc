/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.
*/

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[1] < b[1]) return true;
        else if (a[0] == b[0]) return a[0] < b[0];
        return false;
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        int count = 0;
        sort(events.begin(), events.end(), cmp);
        int upperBound = events[events.size()-1][1]; // at most this many days
        set<int> s;
        for (int i = 1; i <= upperBound; i++) {
            s.insert(i); // holds possible days
        }

        for (auto event : events) {
            int start = event[0];
            int end = event[1];
            auto it = s.lower_bound(start);
            if (it == s.end() || *it > end) continue;
            count += 1;
            s.erase(it);
        }

        return count;
    }
};
