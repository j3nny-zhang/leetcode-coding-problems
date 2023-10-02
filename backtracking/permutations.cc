/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
    void permuteHelper(vector<vector<int>> &result, vector<int> &nums, vector<int> &permutation, int size,  unordered_set<int> &visited) { 
        if (permutation.size() == size) {
            result.push_back(permutation);
            return;
        }
       
        for (int num : nums) {
            if (visited.find(num) != visited.end()) continue;
            visited.insert(num);
            permutation.push_back(num);
            permuteHelper(result, nums, permutation, size, visited);
            permutation.pop_back();
            visited.erase(num);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        unordered_set<int> visited;
        int size = nums.size();

        permuteHelper(result, nums, permutation, size, visited);
        return result;
    }
};
