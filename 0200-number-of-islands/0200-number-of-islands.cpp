class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    grid[i][j] = '0'; // mark visited

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        int r[4] = {-1, 0, 1, 0};
                        int c[4] = {0, 1, 0, -1};
                        for (int i = 0; i < 4; i++) {
                            if (x + r[i] >= 0 && x + r[i] < m && y + c[i] >= 0 &&
                                y + c[i] < n) {
                                if (grid[x + r[i]][y + c[i]] == '1') {
                                    q.push({(x + r[i]), (y + c[i])});
                                    grid[x + r[i]][y + c[i]] = '0';
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};