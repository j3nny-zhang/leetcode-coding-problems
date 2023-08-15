/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size();
        int t = 0;
        int b = matrix.size();

        vector<int> result;

        while (l < r && t < b) {

            // upper left to upper right
            for (int i = l; i < r; i++) {
                result.push_back(matrix[t][i]);
            }
            t += 1;

            // upper right to bottom right
            for (int i = t; i < b; i++) {
                result.push_back(matrix[i][r-1]);
            }
            r -= 1;

            if (l >= r || t >= b) break;

            // bottom right to bottom left
            for (int i = r-1; i >= l; i--) {
                result.push_back(matrix[b-1][i]);
            }
            b -= 1;

            // bottom left to top left
            for (int i = b-1; i >= t; i--) {
                result.push_back(matrix[i][l]);
            }
            l += 1;
        }

        return result;
    }
};
