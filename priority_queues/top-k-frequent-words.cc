/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

class Solution {
public:
    struct cmp {
            bool operator()(pair<int, string> x, pair<int, string> y) {
                if (x.first == y.first) return x.second < y.second;
                return x.first > y.first;
            }
        };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto &word : words) {
            m[word] += 1;
        }  

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto &entry : m) {
            pq.push(pair<int, string>{entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res(k);
        int n = k- 1;
        while (pq.size() > 0) {
            res[n--] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};
