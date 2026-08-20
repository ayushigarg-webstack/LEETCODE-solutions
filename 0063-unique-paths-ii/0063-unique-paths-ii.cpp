class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j, int m, int n)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j]; //this means it is predetermined value so no need to do a recursive call again for it
        int down=0;
        int right=0;
        if(i+1<m && obstacleGrid[i+1][j] != 1) {
            down = solve(obstacleGrid, dp, i+1, j, m, n);
        } 
        if(j+1<n && obstacleGrid[i][j+1] != 1) {
            right = solve(obstacleGrid, dp, i, j+1, m, n);
        }
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        return solve(obstacleGrid, dp, 0, 0, m, n);
    }
};