/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
    int bfs(set<vector<int>> &visited, vector<vector<int>>& grid, int row, int col, int i, int j) {
        if (visited.find({i,j}) != visited.end()) return 0;
        if (grid[i][j] == 0) return 0;
        visited.insert({i,j});
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
        queue<vector<int>> q;
        q.push({i, j});
        int area = 0;

        while(!q.empty()) {
            vector<int> coords = q.front();
            q.pop();
            area += 1;

            for (auto d: dir) {
                int x = coords[0] + d[0];
                int y = coords[1] + d[1];
                if ((x >= 0 && x < row) && (y >= 0 && y < col) && grid[x][y] == 1 && visited.find({x,y}) == visited.end()) {
                    q.push({x, y});
                    visited.insert({x, y});
                }
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<vector<int>> visited;
        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int area = bfs(visited, grid, row, col, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
