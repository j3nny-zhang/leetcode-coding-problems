class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1;
        int l = 0;
        int r = 0;

        if (s.size() == 1) return s;

        // 2d dp array
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        // base case, single character strings
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }

        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] != s[j]) continue;
                if (i == j+1 || dp[i-1][j+1]) {
                    dp[i][j] = true;
                    if (length < i - j + 1) {
                        length = i - j + 1;
                        r = i;
                        l = j;
                    }
                }
            }
        }
        return s.substr(l, length);
    }
};
