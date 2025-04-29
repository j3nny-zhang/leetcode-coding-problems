/**
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        int m = matrix.size();
        int n = matrix[0].size();

        // treat as a 1d array
        int lo = 0; int hi = n * m - 1;
        while (lo <= hi) {
            int middle = (lo + hi) / 2;
            int row = middle / n;
            int col = middle % n;

            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) {
                lo = middle + 1;
            } else {
                hi = middle - 1; 
            }
        }

        return false;
     }
} ;              
