class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool check(vector<vector<int>>& dist, int safe, int n) {
        if (dist[0][0] < safe)
            return false;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();


            if (i == n - 1 && j == n - 1)
                return true;

            for(int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !vis[nx][ny] && dist[nx][ny] >= safe) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }    

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        int low = 0;
        int high = 2 * (n - 1);
        int ans = 0;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (check(dist, mid, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
        
    }
};