class Solution {
    void generateSubsets(int i, vector<int>& nums, vector<vector<int>>& result, vector<int>& combination) {
        if (i >= nums.size()) {
            result.push_back(combination);
            return;
        }

        combination.push_back(nums[i]);
        generateSubsets(i+1, nums, result, combination);
        combination.pop_back();
        generateSubsets(i+1, nums, result, combination);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> combination;

        generateSubsets(0, nums, result, combination);

        return result;
    }
};
