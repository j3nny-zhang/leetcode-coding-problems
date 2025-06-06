/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = INT_MIN;
        int l = 0;
        int zeroes = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeroes += 1;

            while (zeroes > k) {
                if (nums[l] == 0) zeroes -= 1;
                l += 1;
            }

            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
