/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

class Solution {
    int abs(int n) {
        if (n < 0) return -n;
        return n;
    }
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            int n = abs(num) - 1;
            if (nums[n] > 0) nums[n] *= -1;

        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) result.push_back(i+1);
        }

        return result;
    }
};
