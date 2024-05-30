/**
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
**/

class Solution {
    vector<vector<int>> smaller = {{-1, 0}, {0, -1}};
    vector<vector<int>> bigger = {{1, 0}, {0, 1}};

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size() - 1;

        int row = 0;
        int col = n;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) {
                row += 1;
            } else {
                col -= 1;
            }
        }

        return false;
    }
};
