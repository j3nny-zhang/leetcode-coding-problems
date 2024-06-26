/**
There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that 
the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.

Return true if grid represents a valid configuration of the knight's movements or false otherwise.

Note that a valid knight move consists of moving two squares vertically and one square horizontally,
or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
**/

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{-1,-2}, {1,-2}, {2,-1}, {2,1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

        if (grid[0][0] != 0) return false;

        int n = grid.size();

        queue<vector<int>> q;
        q.push({0, 0});
        int move = 1;
        int possible_moves = n * n - 1;

        while (!q.empty()) { // always one element in the queue
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            if (move-1 == possible_moves && grid[x][y] == possible_moves) return true;

            for (vector<int> d : dir) {
                int new_x = x + d[0];
                int new_y = y + d[1];


                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == move) {
                    q.push({new_x, new_y});
                    move += 1;
                }
            }
        }
    
    return false;
    
    }
};
