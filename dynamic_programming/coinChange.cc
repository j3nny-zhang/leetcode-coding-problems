/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) 
                    dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> count(amount+1, -1);
        count[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int value = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && count[i - coin] != -1) {
                    value = min(value, count[i - coin]);
                    count[i] = value + 1;
                }
            }
        }

        return count[amount];
    }
};
