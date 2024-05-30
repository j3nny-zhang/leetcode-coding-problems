// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int size = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base cases, when i = 0, j = 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {dp[i][0] = 1; size = 1;}
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {dp[0][j] = 1; size = 1;}
        }

        // recursive step
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != '0') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }

                size = max(dp[i][j], size);
            }
        }

        return size * size;
    }
};
