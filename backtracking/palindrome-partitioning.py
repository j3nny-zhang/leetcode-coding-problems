'''
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.
 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]
'''

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self.dfs(s, [], result)
        return result

    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]
    
    def dfs(self, s: str, path: List[str], res: List[List[str]]):
        if not s:
            res.append(path)
            return

        for i in range(1, len(s)+1):
            if self.isPalindrome(s[:i]):
                self.dfs(s[i:], path + [s[:i]], res)
