/*
You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. 
To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. 
An example rotation is shown below:

Return the matrix after applying k cyclic rotations to it.
*/

class Solution {

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            int row_u = layer;
            int row_b = m - layer - 1; 

            int col_l = layer;
            int col_r = n - layer - 1;

            vector<int> temp;
            // top: left to right
            for (int i = col_l; i <= col_r; i++) temp.push_back(grid[row_u][i]);
            // right: top to bottom
            for (int i = row_u + 1; i <= row_b; i++) temp.push_back(grid[i][col_r]);
            // bottom: right to left
            for (int i = col_r - 1; i >= col_l; i--) temp.push_back(grid[row_b][i]);
            // left: bottom to top
            for (int i = row_b - 1; i > row_u; i--) temp.push_back(grid[i][col_l]);

            int len = temp.size();
            int shift = k % len;

            // shift left
            vector<int> rotate(len);
            for (int i = 0; i < len; i++) {
                rotate[i] = temp[(i + shift) % len];
            }

            int index = 0;
            // top: left to right
            for (int i = col_l; i <= col_r; i++) grid[row_u][i] = rotate[index++];
            // right: top to bottom
            for (int i = row_u + 1; i <= row_b; i++) grid[i][col_r] = rotate[index++];
            // bottom: right to left
            for (int i = col_r - 1; i >= col_l; i--) grid[row_b][i] = rotate[index++];
            // left: bottom to top
            for (int i = row_b - 1; i > row_u; i--) grid[i][col_l] = rotate[index++];
        }

        return grid;
    }
};
