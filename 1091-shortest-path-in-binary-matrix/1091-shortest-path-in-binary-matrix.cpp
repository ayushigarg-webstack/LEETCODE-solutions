class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int distance = dist[x][y];
            int xr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int yc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            for (int i = 0; i < 8; i++) {
                if (x + xr[i] >= 0 && y + yc[i] >= 0 && x + xr[i] < n && y + yc[i] < n) {
                    if (grid[x + xr[i]][y + yc[i]] == 0) {
                        if (dist[x + xr[i]][y + yc[i]] == -1) {
                            q.push({x + xr[i], y + yc[i]});
                            dist[x + xr[i]][y + yc[i]] = distance + 1;
                        }
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};