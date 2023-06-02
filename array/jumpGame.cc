/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

class Solution {
// my first solution is correct, but not optimal
  
bool helper(int i, vector<int>& nums, unordered_map<int, bool>& memo) {
        if (memo[i]) return false; // already visited
        memo[i] = true;

        if (i == nums.size()-1) return true;
        if (i > nums.size()-1) return false;
        if (nums[i] == 0) return false;

        for (int j = 1; j <= nums[i]; j++) {
            if (helper(i + j, nums, memo)) return true;
        }

        return false;
    }
  
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        unordered_map<int, bool> memo;
        return helper(0, nums, memo);

    }
// -------------------------------------------------------------------
  
// optimal solution
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) return true;
            if (nums[i] == 0 && dist == i) return false;
            dist = max(dist, nums[i] + i);
        }
        return true;
    }
};
