/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // let dp[i] be the longest increasing subsequence until i-1  
        // dp[i] = dp[j] + 1 if we add to subsequence until j, for j <= i
        // dp[i] = dp[i-1] otherwise

        vector<int> dp(nums.size(), 1);

        int res = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

// n^2, but much more intuitive
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

// nlogn
class Solution {
    // returns index of smallest num for which >= k
    // if k < all nums in sub, then return 0;
    // if k > all nums in sub, then return -1;
    int binarySearch(vector<int> & sub, int k) {
        int l = 0;
        int r = sub.size() - 1;
        int mid = 0;

        while (l < r) {
            mid = (l+r) / 2;
            if (l == mid) break;
            if (sub[mid] == k) return mid;
            if (sub[mid] > k) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (sub[mid] < k) return mid + 1;
        if (sub[0] > k) return 0; // smaller than all numbers
        return -1; // bigger than all numbers
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > sub[sub.size()-1]) {
                sub.push_back(nums[i]);
            } else {
                int result = binarySearch(sub, nums[i]);
                if (result != - 1) sub[result] = nums[i];
            }
        } 

        return sub.size();
    }

};
