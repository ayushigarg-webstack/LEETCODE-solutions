
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store {query time, original index}
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m, 0);

        // Frequency of requests for each server
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int active = 0;

        for (auto [time, idx] : q) {

            int start = time - x;

            // Add logs with time <= query time
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            // Remove logs with time < start
            while (left < right && logs[left][1] < start) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    active--;

                left++;
            }

            // Servers without requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
