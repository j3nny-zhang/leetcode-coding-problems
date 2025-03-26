// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // keep track of rows and columns to set to 0
        // sets ensure we don't need to visit rows / cols multiple times
        unordered_set<int> row;
        unordered_set<int> col;

        int m = matrix.size();
        int n = matrix[0].size();

        // get rows and columns that need to be set to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        // set rows and cols to 0
        for (int m : row) {
            for (int j = 0; j < n; j++) matrix[m][j] = 0;
        }

        for (int n : col) {
            for (int i = 0; i < m; i++) matrix[i][n] = 0;
        }
    }
};
