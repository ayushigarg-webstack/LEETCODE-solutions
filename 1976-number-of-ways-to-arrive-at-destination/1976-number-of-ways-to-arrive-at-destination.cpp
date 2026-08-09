class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adjList[n];
        for (auto it : roads) {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ways(n, 0);
        vector<long long> dist(n, 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        int mod = (int)(1e9+7);
        pq.push({0, 0});
        ways[0] = 1;
        dist[0] = 0;
        while (!pq.empty()) {
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adjList[node]) {
                int nextNode = it.first;
                long long weight = it.second;
                long long newDist = weight+distance;
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = weight + distance;
                    pq.push({weight + distance, nextNode});
                    ways[nextNode] = ways[node];
                } else if (dist[nextNode] == weight + distance) {
                    ways[nextNode] = (ways[nextNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};