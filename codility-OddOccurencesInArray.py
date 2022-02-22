'''
A non-empty array A consisting of N integers is given. The array contains an odd 
number of elements, and each element of the array can be paired with another element 
that has the same value, except for one element that is left unpaired.
'''

def solution(A):

    A.sort()

    i = 0

    while i < len(A) - 1:
        if A[i] != A[i + 1]:
            return A[i]
        i += 2 # check every pair of numbers

    return A[-1] # the case where the unpaired number is at the end of the sorted list
