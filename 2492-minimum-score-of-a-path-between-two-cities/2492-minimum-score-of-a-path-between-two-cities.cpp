class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, int &ans) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            int neigh = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[neigh]) {
                dfs(neigh, adj, vis, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;

        dfs(1, adj, vis, ans);

        return ans;
    }
};