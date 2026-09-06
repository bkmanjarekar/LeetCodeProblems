class Solution {
public:
    int numDistinct(string s, string t) {
        int r = t.length();
        int c = s.length();

        vector<vector<unsigned int>> dp (r + 1, vector<unsigned int>(c + 1, 0));

        for (int j = 0; j <= c; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[r][c];
    }
};