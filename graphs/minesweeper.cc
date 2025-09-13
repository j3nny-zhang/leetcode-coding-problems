/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
*/

class Solution {
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
   
    int countMines(int x, int y, int m, int n, vector<vector<char>>& board) {
        int count = 0;

        for (vector<int>& d: dir) {
            int xx = x + d[0];
            int yy = y + d[1];

            if (xx >= 0 && xx < m && yy >= 0 && yy < n && board[xx][yy] == 'M') count += 1;
        }

        return count;
    }
   
   
    void bfs(int x, int y, int m, int n, vector<vector<char>>& board) {
        queue<vector<int>> q;
        q.push({x,y});

        // if an M is clicked:
        //     - change to X
        //     - return 
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        // else do processing on the first cell
        int mines = countMines(x, y, m, n, board);
        if (mines) {
            board[x][y] = '0' + mines;
            return;
        } else {
            board[x][y] = 'B';
        }

        while (!q.empty()) {
            vector<int> coord = q.front(); q.pop();
            
            int count = 0;
            for (vector<int>& d : dir) {
                int xx = coord[0] + d[0];
                int yy = coord[1] + d[1];

                if (xx >= 0 && xx < m && yy >= 0 && yy < n && board[xx][yy] == 'E') {
                    int mines = countMines(xx, yy, m, n, board);

                    if (mines) {
                        // if an E is clicked with at least an adj mine:
                        //     - change digit = num of adj mines
                        board[xx][yy] = '0' + mines;
                    } else {
                        // if an E is clicked with no adjacent mines:
                        //     - change to B
                        //     - reveal adjacent squares recursively
                        board[xx][yy] = 'B';
                        q.push({xx,yy});
                    }
                }
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // perform a bfs from the "click" coordinate
        int m = board.size();
        int n = board[0].size();
        bfs(click[0], click[1], m, n, board);
        return board;
    }
};
