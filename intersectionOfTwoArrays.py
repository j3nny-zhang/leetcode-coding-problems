# find the intersection of two arrays
# example: [1, 2, 2, 1][2, 2] => [2, 2]

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c = Counter(nums1)
        output = []

        for elem in nums2:
            if c[elem] >= 1:
                c[elem] -= 1
                output.append(elem)

        return output
