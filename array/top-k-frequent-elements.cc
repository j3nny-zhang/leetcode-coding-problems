/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        unordered_map<int, int> m; // element, frequency
        for (int num : nums) {
            m[num] += 1;
        }

        priority_queue<pair<int, int>> pq = {};
        pq.push(pair{0, 0});
        int min = INT_MIN;
        for (auto entry : m) {
            if (entry.second >= min) { // no need to add to pq if smaller than min
                pair<int, int> tmp = {entry.second, entry.first}; // tmp<freq, elem>
                pq.push(tmp);
            } else {
                min = entry.second;
            }
        }

        int i = 0;
        while (i < k) {
            res.push_back(pq.top().second); // .second gives elem, not freq
            pq.pop();
            i++;
        }

        return res;
    }
};
