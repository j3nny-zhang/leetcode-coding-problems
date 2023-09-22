"""
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
"""

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        bfs = deque()
        count = 0
        fresh = 0
        row, col = len(grid), len(grid[0])

        directions = [[0,1],[1,0],[-1,0],[0,-1]]

        # initialize fresh with number of fresh oranges
        for i in range(row):
            for j in range(col):
                if (grid[i][j] == 1):
                    fresh += 1
                if (grid[i][j] == 2):
                    bfs.append((i,j))
        
        while (bfs and fresh > 0):
            for i in range(len(bfs)):
                r, c = bfs.popleft()

                if grid[r][c] == 2:
                    for x, y in directions:
                        if (r + x) in range(row) and (c + y) in range(col) and grid[r+x][c+y] == 1:
                            fresh -= 1
                            grid[r+x][c+y] = 2
                            bfs.append((r+x, c+y))
            
            count += 1
        
        return count if fresh == 0 else -1


        
