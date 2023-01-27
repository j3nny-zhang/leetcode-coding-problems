// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:

    int climbStairs(int n) {
        int arr[n + 1];

        arr[0] = 1; // level 0
        arr[1] = 1; // level 1

        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n];
    }
};
