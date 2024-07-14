/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

class Solution {
    int find_next_lowest(vector<int>& nums, int target, int s, int e) {
        int m = 0;
        while (s <= e) {
            m = (s + e) / 2;

            if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            } 
        }

        return s;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        int mid = 0;
        bool found = false;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                found = true;
                break;
            }

            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            } 
        }

        if (!found) return {-1, -1};

        int lower = mid-1;
        int upper = mid+1;
        
        int l = find_next_lowest(nums, target, 0, lower);
        int r = find_next_lowest(nums, target + 1, upper, nums.size() - 1) - 1;

        return {l, r};
    }
};
