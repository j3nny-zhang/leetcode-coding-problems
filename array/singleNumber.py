# Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        keep_track = []

        for elem in nums:
            if elem in keep_track:
                keep_track.remove(elem)
            else:
                keep_track.append(elem)

        return keep_track[0]
