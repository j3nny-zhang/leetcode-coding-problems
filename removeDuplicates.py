## Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
## such that each unique element appears only once. The relative order of the elements should be kept the same.

## ie. modify the array in place
## return the number of elements in the array without duplicates

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        #trivial case
        if not nums:
            return 0
       
       #keep track of every unique number as we iterate through the array
        previous = nums[0] 
        
        for i in nums[1:]:
            if i == previous:
                nums.remove(i)
            else:
                previous = i
        return len(nums)
