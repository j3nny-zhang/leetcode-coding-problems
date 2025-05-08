/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

class Solution {
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;
        vector<int> dp(nums.size(), 0);

        dp[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            int maxVal = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    maxVal = max(maxVal, dp[j] + 1);
            }
            dp[i] = maxVal;
            result = max(result, maxVal);
        }

        return result;
    }
};
