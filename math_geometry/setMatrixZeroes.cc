/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int corner = matrix[0][0];

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 && matrix[i][j] == 0) {
                    corner = 0;
                    continue;
                }
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }

        }

        if (corner == 0) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

    }
};
