/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // {num ; count}
        vector<int> res;

        for (int n : nums) {
            freq[n] += 1;
        }

        // maintain that heap has only k elements
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto &entry : freq) {
            int num = entry.first;
            int count = entry.second;
            
            if (pq.size() >= k) {
                if (pq.top().first < count) {
                    pq.pop();
                    pq.push({count, num});
                }
            } else { // push in first k
                pq.push({count, num}); // sort by count
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
};
