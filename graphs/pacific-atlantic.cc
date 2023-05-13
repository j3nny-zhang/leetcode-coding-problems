/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, 
and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea 
level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height 
is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution {

  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, const int m, const int n) {
      visited[x][y] = true;

      if (x > 0 && heights[x-1][y] >= heights[x][y] && !visited[x-1][y]) {
          dfs(heights, visited, x-1, y, m, n);
      } 
      if (y > 0 && heights[x][y-1] >= heights[x][y] && !visited[x][y-1]) {
          dfs(heights, visited, x, y-1, m, n);
      } 
      if (x < m-1 && heights[x+1][y] >= heights[x][y] && !visited[x+1][y]) {
          dfs(heights, visited, x+1, y, m, n);
      } 
      if (y < n-1 && heights[x][y+1] >= heights[x][y] && !visited[x][y+1]) {
          dfs(heights, visited, x, y+1, m, n);
      }
  }


public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();

      vector<vector<bool>> atlantic(m, vector<bool>(n)); 
      vector<vector<bool>> pacific(m, vector<bool>(n));

      // left, right edge cells
      for (int i = 0; i < m; i++) {
          dfs(heights, pacific, i, 0, m, n);
          dfs(heights, atlantic, i, n - 1, m, n);
      }

      // up, down edge cells
      for (int j = 0; j < n; j++) {
          dfs(heights, pacific, 0, j, m, n);
          dfs(heights, atlantic, m - 1, j, m, n);
      }

      vector<vector<int>> result;

      for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              if (pacific[i][j] && atlantic[i][j]) {
                  vector<int> point = {i, j};
                  result.push_back(point);
              }
          }
      }

      return result;
        
    }
};
