"""
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]

"""

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        heapify(heap)
        result = []

        for x,y in points:
            distance = math.sqrt(x*x + y*y)
            heappush(heap, (distance, [x,y]))
        
        while k > 0:
            k -= 1
            pair = heapq.heappop(heap)
            result.append(pair[1])

        return result
