/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) 
or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships 
(i.e., there are no adjacent battleships).
*/

class Solution {
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    
    void bfs(vector<vector<char>>& board, set<vector<int>> &visited, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        queue<vector<int>> q;
        q.push({i, j});
        visited.insert({i, j});

        while (!q.empty()) {
            auto coord = q.front();
            q.pop();

            for (auto d : dir) {
                int x = coord[0] + d[0];
                int y = coord[1] + d[1];

                if ((x >= 0 && x < m) && (y >= 0 && y < n) && visited.find({x,y}) == visited.end() && board[x][y] == 'X') {
                    q.push({x, y});
                    visited.insert({x, y});
                }
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        set<vector<int>> visited;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited.find({i,j}) == visited.end() && board[i][j] == 'X') {
                    bfs(board, visited, i, j);
                    count += 1;
                }
            }
        }

        return count;
    }
};
