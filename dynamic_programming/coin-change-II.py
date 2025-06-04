'''
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.


Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10]
Output: 1
'''

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:

        memo = [[-1] * (amount + 1) for _ in range(len(coins))] # coins x amount
        # memo[i][j] is the num of ways to make up j using the coins starting at i

        def numOfWays(i, target):
            if target == 0: # 1 way of summing to 0
                return 1
            if i == len(coins):
                return 0 # no more coins left to use
            
            if memo[i][target] != -1:
                return memo[i][target]

            if coins[i] > target: # can't take any more of this coin
                memo[i][target] = numOfWays(i + 1, target) # skip this coin
            else:
                memo[i][target] =  numOfWays(i + 1, target) + numOfWays(i, target - coins[i])

            return memo[i][target]

        
        return numOfWays(0, amount)
