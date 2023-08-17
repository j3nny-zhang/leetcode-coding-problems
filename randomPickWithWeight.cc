// You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

// You need to implement the function pickIndex(), which randomly picks an index in the range 
// [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

// For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), 
// and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

class Solution {
    int sum = 0;
    vector<int> v;
public:
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            v.push_back(v.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int i = rand() % v.back(); // from 0 to sum-1
        return upper_bound(v.begin(), v.end(), i) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
