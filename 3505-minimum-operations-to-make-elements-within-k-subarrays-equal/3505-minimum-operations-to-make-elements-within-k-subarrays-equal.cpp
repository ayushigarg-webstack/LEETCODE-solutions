
class Fenwick {
public:
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }

    // Find position of the k-th element
    int kth(long long k) {
        int idx = 0;

        int mask = 1;
        while (mask * 2 <= n)
            mask *= 2;

        for (; mask > 0; mask /= 2) {
            int next = idx + mask;

            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
        }

        return idx + 1;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Step 1: Coordinate compression
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        vector<int> id(n);

        for (int i = 0; i < n; i++) {
            id[i] = lower_bound(vals.begin(), vals.end(), nums[i])
                    - vals.begin() + 1;
        }

        // Step 2: Two Fenwick Trees
        Fenwick freq(m), sum(m);

        vector<long long> cost(n - x + 1);

        long long totalSum = 0;

        for (int i = 0; i < n; i++) {

            // Insert current element
            freq.update(id[i], 1);
            sum.update(id[i], nums[i]);

            totalSum += nums[i];

            // Remove element outside window
            if (i >= x) {
                freq.update(id[i - x], -1);
                sum.update(id[i - x], -nums[i - x]);

                totalSum -= nums[i - x];
            }

            // Calculate cost when window size becomes x
            if (i >= x - 1) {

                // Find median
                int mid = freq.kth((x + 1) / 2);

                long long median = vals[mid - 1];

                // Count and sum of elements <= median
                long long leftCount = freq.query(mid);
                long long leftSum = sum.query(mid);

                // Calculate minimum operations
                long long rightCount = x - leftCount;
                long long rightSum = totalSum - leftSum;

                cost[i - x + 1] =
                    median * leftCount - leftSum +
                    rightSum - median * rightCount;
            }
        }

        // Step 3: Dynamic Programming
        const long long INF = 4e18;

        // dp[j][i] = minimum cost to select
        // j non-overlapping windows in first i elements

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select subarray of size x ending at i-1
                if (i >= x && prev[i - x] != INF) {

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
