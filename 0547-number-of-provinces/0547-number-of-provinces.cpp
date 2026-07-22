class Solution {
public:
    int bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        queue<int> q;
        
        vector<int> visited(V,0);
        int count=0;
        for(int j = 0; j < V; j++)
        {
            if(!visited[j]) 
            { 
                q.push(j);
                visited[j] = true;
                count++;
            }
            while (!q.empty()) 
            {
                int node = q.front();
                q.pop();
                for (int i = 0; i < V; i++) {
                    if (adj[node][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        return bfs(isConnected);
    }
};