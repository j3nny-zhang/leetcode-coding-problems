// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// You must solve it in O(n) time complexity.

 
// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

class Solution {
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;

        while (k > 0) {
            pq.push(nums[i++]);
            k -= 1;
        }

        for (; i < nums.size(); i++) {
            int top = pq.top();
            if (nums[i] > top) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
        
    }
        
};
