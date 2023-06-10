/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.


Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        unordered_map<int, bool> m; // {int, bool} = {value, visited}
        for (int n : nums) {
            m[n] = false;
        }

        int longest, length = 1;

        for (int n : nums) {
            if (m[n]) continue;

            length = 1;
            int copy = n;
            m[n] = true; // have visited the value already
            while (m.find(copy - 1) != m.end()) {
                m[copy - 1] = true;
                length += 1;
                copy -= 1;
            }
            longest = max(longest, length);
        }

        return longest;
    }
    
};

// came up with a more optimal solution, nlogn 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int longest = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i] - 1) {
                count += 1;
            } else if (nums[i-1] == nums[i]) {
                continue;
            } else {
                count = 1;
            }
            longest = max(longest, count);
        }

        return longest;
    }
};
