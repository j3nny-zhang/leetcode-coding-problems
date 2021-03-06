/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int temp = maxProd;
            
            maxProd = max(nums[i], max(maxProd * nums[i], minProd * nums[i]));           
            minProd = min(nums[i], min(temp * nums[i], minProd * nums[i]));
            
            prod = max(prod, maxProd);
        }
        return prod;
    }
};
