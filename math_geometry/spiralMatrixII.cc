// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            result.push_back(row);
        }

        int num = 1;
        int l = 0;
        int r = n;
        int t = 0;
        int b = n;

        while (l < r && t < b) {

            // fill top left to top right
            for (int i = l; i < r; i++) {
                result[t][i] = num++;
            }
            t += 1;
            if (t >= b) break;
            
            // fill top right to bottom right
            for (int i = t; i < b; i++) {
                result[i][r-1] = num++;
            }
            r -= 1;
            if (r <= l) break;

            // fill bottom right to bottom left
            for (int i = r-1; i >= l; i--) {
                result[b-1][i] = num++;
            }
            b -= 1;
            if (b <= t) break;

            // bottom left to top left
            for (int i = b-1; i >= t; i--) {
                result[i][l] = num++;
            }
            l += 1;
            if (l >= r) break;
        }

        return result;
    }
};
