/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

class Solution {
    void combinationSumHelper(int i, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination) {

        if (i == candidates.size()) return;
        if (target == 0) {
            result.push_back(combination);
            return;
        } 

        if (candidates[i] <= target) { // can repeat candidates[i] in combincation
            combination.push_back(candidates[i]); // include in subset
            combinationSumHelper(i, candidates, target - candidates[i], result, combination);
            combination.pop_back(); // do not include in subset
        }
        combinationSumHelper(i + 1, candidates, target, result, combination);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;

        combinationSumHelper(0, candidates, target, result, combination);

        return result;
    }
};
