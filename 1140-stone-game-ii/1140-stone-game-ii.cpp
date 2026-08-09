class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // All piles have been taken
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Can take X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);

            // Current player gets:
            // total remaining stones - opponent's best possible result
            int current = suffix[i] - solve(i + X, newM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can become at most n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};