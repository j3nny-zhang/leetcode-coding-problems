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
