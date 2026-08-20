class Solution {
public:
int t[201][201];
    int f(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i==m-1 && j==n-1) return grid[i][j];
        if(t[i][j] != -1) return t[i][j];
        if(i==m-1) {
            return t[i][j] = grid[i][j]+f(grid,i,j+1,m,n);
        } else if(j==n-1) {
            return t[i][j] = grid[i][j]+f(grid,i+1,j,m,n);
        } else {
            return t[i][j] = grid[i][j]+min(f(grid,i,j+1,m,n),f(grid,i+1,j,m,n));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return f(grid,0,0,m,n);
    }
};