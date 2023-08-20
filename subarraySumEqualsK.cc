// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>  prevSums; // {sum, num of that sum}
        int currSum = 0;

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (currSum == k) result += 1;
            if (prevSums.find(currSum - k) != prevSums.end()) result += prevSums[currSum - k];
            prevSums[currSum] += 1;
        }

        return result;
    }
};
