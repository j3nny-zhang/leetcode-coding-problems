/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
*/

class Solution {
    void findSubsets(int i, vector<int>& nums, vector<int>& combination, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(combination);
            return;
        }

        combination.push_back(nums[i]);
        findSubsets(i+1, nums, combination, result);
        combination.pop_back();

        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            i += 1;
        }
        findSubsets(i+1, nums, combination, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(nums.begin(), nums.end());

        findSubsets(0, nums, combination, result);
        return result;
    }
};
