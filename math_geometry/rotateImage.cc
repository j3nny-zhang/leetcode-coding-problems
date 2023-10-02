/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        int l = 0;
        int r = n;

        while (l < r) {
            for (int i = 0; i < r - l; i++) {
                int t = l;
                int b = r;

                int topLeft = matrix[t][l+i]; // top left

                // bottom left to top left
                matrix[t][l+i] = matrix[b-i][l];

                // bottom right to bottom left
                matrix[b-i][l] = matrix[b][r-i]; 

                // top right to bottom right
                matrix[b][r-i] = matrix[t+i][r];

                // top left to top right
                matrix[t+i][r] = topLeft;
                
            }

            l += 1;
            r -= 1;
        }
        
     }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       reverse(matrix.begin(), matrix.end());
       for (int i = 0; i < matrix.size(); i++) {
           for (int j = 0; j < i; j++) {
               swap(matrix[i][j], matrix[j][i]);
           }
       }
    }
};
