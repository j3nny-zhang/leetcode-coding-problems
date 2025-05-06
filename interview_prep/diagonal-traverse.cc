Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res(m*n);
        int i = 0;
        int j = 0;
        int index = 0;

        bool isUp = true;

        while (index != res.size()) {
            if (!isUp) {
                isUp = true;

                while (i < m && j >= 0) {
                    if (j < n) res[index++] = mat[i][j];
                    i += 1;
                    j -= 1;
                }
                j += 1;
            } else {
                isUp = false;

                while (i >= 0 && j < n) {
                    if (i < m) res[index++] = mat[i][j];
                    i -= 1;
                    j += 1;
                }
                i += 1;
            }
        }
        return res;
    }
};
