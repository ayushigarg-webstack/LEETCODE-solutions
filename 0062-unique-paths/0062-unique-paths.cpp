class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, int m, int n)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1, j, dp, m, n);
        int right = f(i, j+1, dp, m, n);
        return dp[i][j] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(0, 0, dp, m, n);
    }
};