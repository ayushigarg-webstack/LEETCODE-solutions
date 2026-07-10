class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                           vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n);
        vector<int> values(n);

        for(int i = 0; i < n; i++) {
            values[i] = a[i].first;
            pos[a[i].second] = i;
        }

        // rightMost using two pointers
        vector<int> rightMost(n);
        int r = 0;
        for(int l = 0; l < n; l++) {
            while(r + 1 < n && values[r + 1] - values[l] <= maxDiff)
                r++;
            rightMost[l] = r;
        }

        // connected components
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;

        for(int i = 1; i < n; i++) {
            if(values[i] - values[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = rightMost[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            if(u > v)
                swap(u, v);

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int jumps = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};