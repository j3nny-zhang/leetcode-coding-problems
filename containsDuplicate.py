# return true if the list contains a dupicate:

# version with recursion:
def containsDuplicate(nums: List[int]) -> bool:
  if not nums:
    return False
  else:
    previous = nums[0]
    
  for elem in nums[1:]:
    if elem == previous:
      return True
    
   return containsDuplicate(nums[1:])

# second version:
def containsDuplicate(nums: List[int]) -> bool:
    print("nums: ", nums)

    new_list = []

    i = 0
    while i < len(nums):
        if nums[i] in new_list:
            return True
        else:
            new_list.append(nums[i])
            i += 1

    return False

# third version:
def containsDuplicate(nums: List[int]) -> bool:
    numSet = set(nums)

    if len(numSet) == len(nums):
        return False
    return True
