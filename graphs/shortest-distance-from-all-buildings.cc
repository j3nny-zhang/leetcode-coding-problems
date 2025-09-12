/*
You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.
*/

class Solution {
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void calculateDistances(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& distances, vector<vector<int>>& reachable, int m, int n) {
        vector<vector<int>> visited(m, vector<int>(n, false));
        vector<vector<int>> localDistances(m, vector<int>(n, 0));
        vector<vector<int>> localReachable(m, vector<int>(n, 0));

        queue<vector<int>> q;
        visited[x][y] = true;
        q.push({x, y});

        while (!q.empty()) {
            vector<int> coord = q.front(); q.pop();
            

            for (auto &d : dir) {
                int xx = coord[0] + d[0];
                int yy = coord[1] + d[1];

                if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy] && grid[xx][yy] == 0) {
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                    localDistances[xx][yy] = localDistances[coord[0]][coord[1]] + 1;
                    localReachable[xx][yy] += 1;
                }
            }
        }

        // copy over local distances to distance
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distances[i][j] += localDistances[i][j];
                reachable[i][j] += localReachable[i][j];
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return -1;

        vector<vector<int>> distances(m, vector<int>(n, 0));
        vector<vector<int>> reachable(m, vector<int>(n, false));

        int minDistance = INT_MAX; 
        int buildings = 0;     

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) distances[i][j] = INT_MAX;
                if (grid[i][j] == 1) {
                    buildings += 1;
                    calculateDistances(i, j, grid, distances, reachable, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reachable[i][j] == buildings)
                    minDistance = min(minDistance, distances[i][j]);
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};
