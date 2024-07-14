/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

class Solution {
    void make_combinations(int i, vector<int>& combination, vector<int>& candidates, int sum, int target, vector<vector<int>>& combinations) {
        if (sum > target) return;
        if (target == sum){ 
            combinations.push_back(combination);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            if (target - candidates[j] >= 0) {
                combination.push_back(candidates[j]);
                sum += candidates[j];
                make_combinations(j+1, combination, candidates, sum, target, combinations);
                combination.pop_back();
                sum -= candidates[j];
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        make_combinations(0, combination, candidates, 0, target, combinations);

        return combinations;
    }
};
