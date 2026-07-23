class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> output(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            output[r][c]=dist;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    if(!visited[nrow][ncol] && mat[nrow][ncol]==1)
                    {
                        visited[nrow][ncol]=1;
                        q.push({{nrow,ncol},dist+1});
                    }
                }
            }
        }
        return output;
    }
};