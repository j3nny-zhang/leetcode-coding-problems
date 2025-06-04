class Solution:
    def longestPalindrome(self, s: str) -> str:
        # let dp[i][j] be if the substring s[i : j] is a valid palindrome
        # if s[i] == s[j], then dp[i-1][j+1] is a palindrome

        # base cases:
        # each letter on its own is a valid palindrome dp[i][i] = True
        # if s[i] == s[i+1] then dp[i][i+1] is a palindrome (accounts for even length)

        n = len(s)
        dp = [[False] * n for _ in range(n)]
        indices = [0, 0]
        length = 0

        for i in range(n):
            dp[i][i] = True
        
        for i in range(n - 1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True
                indices = [i, i+1]

        for j in range(1, n):
            for i in range(j):
                if (s[i] == s[j] and dp[i+1][j-1]):
                    dp[i][j] = True
                    if length < j - i + 1:
                        indices = [i, j]
                        length = j - i + 1
        
        start = indices[0]
        end = indices[1]

        return s[start : end + 1]
