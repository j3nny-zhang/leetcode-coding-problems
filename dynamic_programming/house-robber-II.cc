/**
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
**/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)  return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        // basically do dp twice
        int n = nums.size() - 1;
        return (max(robHelper(nums, 0, n-1), robHelper(nums, 1, n)));

    }
private:
    int robHelper(vector<int>& nums, int l, int r) {
        int prev = 0;
        int curr = 0;
        int next = 0;

        for (int i = l; i <= r; i++) {
            next = max(curr, prev + nums[i]);
            prev = curr;
            curr = next;
        }

        return curr;
    }
};
