/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on 
the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (board[i][j] == 'X') return;
        if (visited[i][j]) return;

        visited[i][j] = true;

        dfs(i+1, j, m, n, board, visited);
        dfs(i, j+1, m, n, board, visited);
        dfs(i-1, j, m, n, board, visited);
        dfs(i, j-1, m, n, board, visited);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // mark all components of o's that touch the edge as "visited"
        // this is because they cannot be "surrounded"

        // row
        for (int i = 0; i < n; i++) { // board[0][i]
            if (board[0][i] == 'O')
            dfs(0, i, m, n, board, visited);
        }

        for (int i = 0; i < n; i++) { // board[m-1][i]
            if (board[m-1][i] == 'O')
            dfs(m-1, i, m, n, board, visited);
        } 

        // column
        for (int i = 0; i < m; i++) { // board[i][0]
            if (board[i][0] == 'O')
            dfs(i, 0, m, n, board, visited);
        }

        for (int i = 0; i < m; i++) { // board[i][n-1]
            if (board[i][n-1] == 'O')
            dfs(i, n-1, m, n, board, visited);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
