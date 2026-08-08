class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adjList[n+1];
        for (auto it : times) {
            adjList[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (distance > dist[node])
                continue;
            for (auto it : adjList[node]) {
                int nextNode = it.first;
                int weight = it.second;
                if (distance + weight < dist[nextNode]) {
                    dist[nextNode] = weight + distance;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i]==1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};