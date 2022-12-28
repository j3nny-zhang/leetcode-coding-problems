'''
Write a function:

def solution(A)
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
'''

def solution(A):
    # write your code in Python 3.6

    for i in range(len(A)):
        if A.count(i + 1) == 0:
            return i + 1
    
    return max(A) + 1
  
 # need to find a more efficient solution
