/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

*/

class Solution { // breadth first solution
public:
    int wrapper(int x, int y, set<pair<int, int>> &visited, int &row_len, int &col_len, vector<vector<char>>& grid) {
        bool x_bounds = (0 <= x && x < row_len);
        bool y_bounds = (0 <= y && y < col_len);

        if (!x_bounds || !y_bounds) return false;
        if (grid[x][y] == '0') return false;

        pair<int, int> pos = {x, y};
        if (visited.find(pos) != visited.end()) return false;
        visited.insert(pos);

        wrapper(x + 1, y, visited, row_len, col_len, grid);
        wrapper(x - 1, y, visited, row_len, col_len, grid);
        wrapper(x, y + 1, visited, row_len, col_len, grid);
        wrapper(x, y - 1, visited, row_len, col_len, grid);

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();

        set<pair<int, int>> visited;

        int count = 0;

        for (int i = 0; i < row_len; i++) {
            for (int j = 0; j < col_len; j++) {
                if (wrapper(i, j, visited, row_len, col_len, grid)) count++;
            }
        }

        return count;
    }
  
// neetcode dfs solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    result++;
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};
};
