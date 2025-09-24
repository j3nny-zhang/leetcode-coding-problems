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
public:
    int binarySearch(vector<int>& nums, int target, bool left) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r-l) / 2;

            if (nums[mid] == target) {
                if (left) {
                    if (mid == 0 || nums[mid-1] != target) return mid;
                    r = mid - 1;
                } else {
                    if (mid == nums.size() - 1 || nums[mid+1] != target) return mid;
                    l = mid + 1;
                }
            }  else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binarySearch(nums, target, true);
        int r = binarySearch(nums, target, false);

        if (l == -1 || r == -1) return {-1, -1};
        return {l, r};
    }
};
