/**
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
**/

class Solution {
    vector<vector<int>> dirs = {{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;

        queue<vector<int>> q; // pair = {x, y} coord
        q.push({0, 0}); // top left
        grid[0][0] = 1;

        int length = 1;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                vector<int> tovisit = q.front();
                q.pop();
                if (tovisit[0] == n-1 && tovisit[1] == n-1) return length;

                for (auto &dir : dirs) {
                    int x = tovisit[0] + dir[0];
                    int y = tovisit[1] + dir[1];

                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            length += 1;
        }
        return -1;
    }
};
