class Solution {
public:
    int squareSum(int n) {
        int sum = 0;

        while (n != 0) {
            int mod = n % 10;
            sum += mod * mod;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (true) {
            int result = squareSum(n);
            cout << result << endl;
            if (result == 1) return true;
            if (seen.find(result) != seen.end()) return false;

            seen.insert(result);

            n = result;
        }
    }
};
