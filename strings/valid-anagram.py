'''
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
  
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
'''

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = [0] * 26

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            letters[ord(s[i]) - 97] += 1
            letters[ord(t[i]) - 97] -= 1
        
        for count in letters:
            if count != 0:
                return False
        

        return True
