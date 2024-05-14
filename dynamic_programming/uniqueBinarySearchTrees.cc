// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

class Solution {
    unordered_map<int, int> mem; // {i, res}
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        
        int res = 0;
        if (mem.contains(n)) return mem[n];


        for (int i = 1; i <= n; i++) {
            res += numTrees(i - 1) * numTrees(n - i);
        }

        return mem[n] = res;
    }
};
