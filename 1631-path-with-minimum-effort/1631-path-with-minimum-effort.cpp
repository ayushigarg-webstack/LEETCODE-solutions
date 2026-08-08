class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i = 0; i < 4; i++)
            {
                int nx = row+dr[i];
                int ny = col+dc[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    int newEffort = max(abs(heights[row][col]-heights[nx][ny]), diff);
                    if(newEffort < dist[nx][ny])
                    {
                        dist[nx][ny] = newEffort;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};