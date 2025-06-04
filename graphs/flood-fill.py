'''
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, 
either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original 
color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
'''

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        
        bfs = deque()
        visited = [[False] * n for _ in range(m)]

        visited[sr][sc] = True
        bfs.append([sr, sc])
        originalColor = image[sr][sc]

        directions = [[0, 1], [1, 0], [0,-1], [-1, 0]]

        while bfs:
            x, y = bfs.popleft()
            image[x][y] = color

            for d in directions:
                xx = x + d[0]
                yy = y + d[1]

                if xx >= 0 and xx < m and yy >= 0 and yy < n and not visited[xx][yy] and image[xx][yy] == originalColor:
                    visited[xx][yy] = True
                    bfs.append([xx, yy])

        
        return image
