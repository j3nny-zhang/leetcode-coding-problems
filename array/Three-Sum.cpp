/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/

class Solution {
public:
    void twoSum(vector<int>& nums, int target, int left, vector<vector<int>> &result) {
        int l = left + 1;
        int r = nums.size()-1;

        while (l < r) {
            if (nums[l] + nums[r] == target) {
                result.push_back(vector<int>{nums[left], nums[l], nums[r]});
                l += 1;
                r -= 1;
                while (nums[l] == nums[l-1] && l < r) l += 1;
            } else if (nums[l] + nums[r] > target) {
                r -= 1;
            } else {
                l += 1;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // duplicates
            twoSum(nums, -nums[i], i, result);
        }

        return result;
    }
};

// ------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < nums.size();) {
            auto target = -nums[i];
            int l = i + 1;
            int r = nums.size()-1;
            
            while(l < r) {
                auto sum = nums[l] + nums[r];
                if (sum < target) { // left pointer forward
                    while(++l < nums.size() && nums[l] == nums[l-1]); // skip #2 duplicates
                } else if (target < sum) { // shift right pointer backward
                    while(--r < nums.size() && nums[r] == nums[r + 1]); // skip #3 duplicates
                } else {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(++l < nums.size() && nums[l] == nums[l-1]); // skip #2 duplicates
                    while(--r < nums.size() && nums[r] == nums[r + 1]); // skip #3 duplicates
                }
            }
            
            while(++i < nums.size() && nums[i] == nums[i - 1]); // skip #1 duplicates
        }
        
        return result;
    }
};
