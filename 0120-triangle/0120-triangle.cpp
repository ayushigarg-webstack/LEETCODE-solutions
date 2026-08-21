class Solution {
public:
    // int f(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
    //     if(i==triangle.size()-1) return triangle[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int down = f(triangle, i+1, j, dp);
    //     int diagonal =  f(triangle, i+1, j+1, dp);
    //     return dp[i][j] = triangle[i][j] + min(down,diagonal);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for(int i = n-2; i >= 0; i--) {
            for(int j=0; j<=i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};