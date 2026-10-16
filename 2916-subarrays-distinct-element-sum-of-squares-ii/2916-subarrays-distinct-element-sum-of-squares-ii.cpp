
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2LL * val * tree[node].sum
             + val * val % MOD * len) % MOD;

        tree[node].sum =
            (tree[node].sum + val * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r,
              tree[node].lazy);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq +
             tree[node * 2 + 1].sumSq) % MOD;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r,
               ql, qr, val);

        pull(node);
    }

    long long query(int node, int l, int r,
                    int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node].sumSq;

        push(node, l, r);

        int mid = l + (r - l) / 2;

        return (query(node * 2, l, mid, ql, qr)
              + query(node * 2 + 1, mid + 1, r,
                      ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            // Add x to every subarray ending at r.
            // Only starts after the previous occurrence
            // gain one new distinct element.
            int left = last[x] + 1;

            update(1, 0, n - 1, left, r, 1);

            ans = (ans +
                   query(1, 0, n - 1, 0, r)) % MOD;

            last[x] = r;
        }

        return ans;
    }
};
