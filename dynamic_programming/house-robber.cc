/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

*/



class Solution { // my solution
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> copy_arr(nums.size(), 0); // dynamic
        copy_arr[0] = nums[0];
        copy_arr[1] = nums[1];
        copy_arr[2] = nums[0] + nums[2];

        int max_val = max(copy_arr[0], copy_arr[1]);
        max_val = max(max_val, copy_arr[2]);

        for (int i = 3; i < nums.size(); i++) {
            copy_arr[i] = max(nums[i] + copy_arr[i-2], nums[i] + copy_arr[i-3]);
            max_val = max(max_val, copy_arr[i]);
            cout << max_val << endl;
        }

        return max_val;
    }
};

class Solution { // optimal solution from neetcode
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};

Class Solution { // my most intuitive solution (personally)
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};
