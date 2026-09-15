class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromic substrings
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // that can be selected from i onwards
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't choose anything starting at i
            dp[i] = dp[i + 1];

            // Try every palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (pal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};