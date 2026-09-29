class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // If starting cell is ')', impossible
        if (grid[0][0] == ')')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(m + n, false)
            )
        );

        // Starting cell '(' gives balance 1
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance < m + n; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    // We cannot have negative balance
                    if (newBalance < 0)
                        continue;

                    // We can come from above
                    if (i > 0 && dp[i - 1][j][balance])
                        dp[i][j][newBalance] = true;

                    // We can come from left
                    if (j > 0 && dp[i][j - 1][balance])
                        dp[i][j][newBalance] = true;
                }
            }
        }

        // Valid parentheses string must finish with balance 0
        return dp[m - 1][n - 1][0];
    }
};