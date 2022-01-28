# Find and return the maximum profit you can achieve.
# Example 1:

'''
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
'''

def maxProfit(self, prices: List[int]) -> int:
        previous = prices[0]
        
        overallProfit = 0

        for elem in prices[1:]:
            
            if elem < previous:
                previous = elem
            else:
                overallProfit += (elem - previous)
                previous = elem

        return overallProfit
