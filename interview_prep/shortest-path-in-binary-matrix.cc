/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dir {
            {0,1}, {0,-1}, {1,0}, {-1,0}, {1,-1}, {-1,1}, {-1,-1}, {1,1}
        };

        queue<vector<int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int path = 1;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();

                if (x == n-1 && y == n-1) return path;

                for (vector<int> & d : dir) {
                    int xx = x + d[0];
                    int yy = y + d[1];

                    if (xx >= 0 && xx < n && yy >=0 && yy < n && grid[xx][yy] == 0) {
                        grid[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }
            }
            path += 1;
        }

        return -1;
    }
};
