// Runtime: 3 ms, faster than 81.08% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 10 MB, less than 95.53% of C++ online submissions for Find Minimum in Rotated Sorted Array.

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int end = nums.size() - 1;
        int mid;
        
        // since the elements are originally in ascending order, we want ceil(mid):
        if ((front + end) % 2 != 0) {
                mid = ((front + end) / 2) + 1;
            } else {
                mid = (front + end) / 2;
            }
        
        //base check - no shift
        if (nums[front] < nums[end]) return nums[front];
        
        while(true) {
            if (front - mid == 0) return nums[front];
            if (end - mid == 0) return nums[end];
            
            if (abs(nums[front] - nums[mid]) > abs(nums[end] - nums[mid])) {
                end = mid;
            } else {
                front = mid;
            }
            
            // ceil(mid)
            if ((front + end) % 2 != 0) {
                mid = ((front + end) / 2) + 1;
            } else {
                mid = (front + end) / 2;
            }            
        }
    }
};
