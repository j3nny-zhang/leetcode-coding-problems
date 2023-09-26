"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        leftBound = deque()
        rightBound = deque()
        
        # create left bound
        bound = 0
        for n in height:
            leftBound.append(bound)
            bound = max(bound, n)

        # create right bound
        bound = 0 
        for n in reversed(height):
            rightBound.appendleft(bound)
            bound = max(bound, n)
        
        result = 0
        for i in range(len(height)):
            toadd = min(leftBound[i], rightBound[i]) - height[i]
            if toadd > 0:
                result += toadd

        return result
