/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lv(nums.size(), 1);
        vector<int> rv(nums.size(), 1);
        vector<int> prod(nums.size(), 1);
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            lv[i+1] = lv[i]*nums[i];
        }
        
        for (int i = nums.size() - 1; i > 0; --i) {
            rv[i-1] = rv[i]*nums[i];
        }
        
        for (int j = 0; j < nums.size(); ++j) {
            prod[j] = lv[j]*rv[j];
        }
        
        return prod;
    }
};
