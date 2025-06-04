/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
*/

class Solution {
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, int& area, int islandID) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid.size()) return;
        if (visited[x][y] != 0) return;
        if (grid[x][y] == 0) return;

        visited[x][y] = 1;
        grid[x][y] = islandID;
        
        area += 1;

        dfs(x + 1, y, grid, visited, area, islandID);
        dfs(x - 1, y, grid, visited, area, islandID);
        dfs(x, y + 1, grid, visited, area, islandID);
        dfs(x, y - 1, grid, visited, area, islandID);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxArea = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int islandID = 1;
        unordered_map<int, int> sizeOfIsland; // {islandID, size}

        // run normal dfs but "colour" each island with an id
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, grid, visited, area, islandID);
                    
                    sizeOfIsland[islandID] = area;
                    maxArea = max(area, maxArea);
                    islandID += 1;
                }
            }
        }

        // now for each "0", we look at the islands surrounding in the immediate n,e,s,w direction
        // flipping this 0 may be able to connect 1+ adjacent islands

        // reset visited vector
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] == 0;
            }
        }


        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int sum = 0;
                    unordered_set<int> seenIDs;
                    
                    if (visited[i][j]) continue;
                    
                    for (auto& d : dir) {
                        int xx = i + d[0];
                        int yy = j + d[1];

                        // check if this coordinate is a part of another island
                        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;

                        // make sure we don't double count
                        
                        if (seenIDs.find(grid[xx][yy]) == seenIDs.end()) {
                            sum += sizeOfIsland[grid[xx][yy]];
                            seenIDs.insert(grid[xx][yy]);

                        }
                    }
                    maxArea = max(maxArea, sum + 1);
                    visited[i][j] = 1;
                }
            }
        }
        
        return maxArea;
    }
};
