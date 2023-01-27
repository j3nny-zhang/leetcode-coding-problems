// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], 
// then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        int operate = abs(x);
        int result = 0;

        while (operate > 0) {
            if (result > INT_MAX / 10) return 0; // account for overflow
            result *= 10;
            result += operate % 10;
            operate /= 10;
        }

        if (x >= 0) {
            return result;
        } else {
            return 0 - result;
        }
    }
};
