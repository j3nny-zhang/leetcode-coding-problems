// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
    // long long n to avoid overflow issues
    double binaryExp(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / binaryExp(x, -1 * n);

        if (n % 2 == 1) return x * binaryExp(x * x, (n - 1) / 2);
        return binaryExp(x * x, n / 2);
    }
public:
    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};
