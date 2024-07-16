/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/

class Solution {
    int m = 0;
    int n = 0;

    bool wordSearch(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, int index, string word) {
        if (index == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[index]) return false;
        if (visited[i][j]) return false;
        visited[i][j] = true;

        // dfs in all directions
        bool res =  // left, down, right, up
            wordSearch(board, i+1, j, visited, index + 1, word) ||
            wordSearch(board, i, j+1, visited, index + 1, word) ||
            wordSearch(board, i-1, j, visited, index + 1, word) ||
            wordSearch(board, i, j-1, visited, index + 1, word);

        visited[i][j] = false;

        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (wordSearch(board, i, j, visited, 0, word) && board[i][j] == word[0]) return true;
            }
        }

        return false;
    }
};
