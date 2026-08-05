class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool> &suspicious)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                suspicious[it] = true;
                dfs(it, adj, vis, suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &edge : invocations)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> vis(n,false);
        vector<bool> suspicious(n,false);
        suspicious[k] = true;
        dfs(k, adj, vis, suspicious);
        for(auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];
            if(!suspicious[u] && suspicious[v])
            {
                vector<int> ans;
                for(int i = 0; i < n; i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(!suspicious[i])
                ans.push_back(i);
        }
        return ans;
    }
};