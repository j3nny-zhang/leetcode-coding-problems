/**
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally 
left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
**/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // let dp[i][j] be the min falling path sum up until matrix[i][j]
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // base cases:
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // recursive case
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                    continue;
                }

                if (j == n-1) {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
                    continue;
                }

                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) + matrix[i][j];
            }
        }

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[n-1][j]);
        }

        return result;
    }
};
