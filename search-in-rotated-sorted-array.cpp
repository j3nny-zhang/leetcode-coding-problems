/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int end = nums.size() - 1;
        int mid = (front + end) / 2;

        // strategy: find pivot point to create sorted subarray, then use binary search on that subarray
        int pivot;

        // find pivot point 
        while (true) {
            if (front - mid == 0) break;
            if (end - mid == 0) break;
            
            if (abs(nums[front] - nums[mid]) > abs(nums[end] - nums[mid])) {
                end = mid;
            } else {
                front = mid;
            }
            mid = (front + end) / 2;
        }

        // binary search in subarray...
        front = 0;
        end = nums.size() - 1;
        if (nums[front] < nums[end]) { // base check, if nums hasn't been shifted
            pivot = end;
        } else {
            pivot = mid;
        }

        if (target == nums[pivot]) {
            return pivot;
        }    

        // 1. find subarray bounds
        if (target > nums[front]) { 
            end = pivot - 1;
        } else if (target < nums[front]) {
            front = pivot + 1;
        } else {
            return front;
        }
        
        
        // 2. binary search
        while (front <= end) {
            mid = (front + end) / 2;

            if (nums[mid] < target) {
                front = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else { 
                break;
            }
        } 

        if (nums[mid] != target) return -1;
        return mid;
    }
};
