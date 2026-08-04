class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outdegree;
        queue<int> q;
        for (int i = 0; i < graph.size(); i++) {
            outdegree.push_back(graph[i].size());
        }
        for (int i = 0; i < outdegree.size(); i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }
        int n = graph.size();
        vector<vector<int>> rev(n);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                rev[v].push_back(u);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: rev[node])
            {
                outdegree[it]--;
                if(outdegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};