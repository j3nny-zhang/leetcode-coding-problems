/**
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
**/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum = 0;
        int i = 0;
        int j = 0;
        int minLength = INT_MAX;
        int subArrayLength = 0;

        bool foundSubarray = false;

        while (j < nums.size()) { 
            currSum += nums[j];

            while (currSum >= target && i <= j) {
                minLength = min(minLength, j - i + 1);
                currSum -= nums[i];
                i += 1;
                foundSubarray = true;
            } 


            j += 1;
        }

        return foundSubarray ? minLength : 0;
    }
};
