class Solution {
public:

    struct Node {
        int prod = 1;
        int cnt[5] = {};
        bool empty = true;
    };

    int k;

    Node merge(const Node& A, const Node& B) {

        if (A.empty) return B;
        if (B.empty) return A;

        Node C;
        C.empty = false;

        // Product of entire segment
        C.prod = (A.prod * B.prod) % k;

        // Prefixes ending inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] = A.cnt[r];
        }

        // Prefixes which contain all of A
        // and then take a prefix of B
        for (int r = 0; r < k; r++) {

            int newRemainder = (A.prod * r) % k;

            C.cnt[newRemainder] += B.cnt[r];
        }

        return C;
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        k = K;

        int n = nums.size();

        // Iterative segment tree
        int size = 1;

        while (size < n)
            size <<= 1;

        vector<Node> seg(2 * size);

        // -------------------------
        // Build leaf nodes
        // -------------------------

        for (int i = 0; i < n; i++) {

            int rem = nums[i] % k;

            seg[size + i].empty = false;
            seg[size + i].prod = rem;
            seg[size + i].cnt[rem] = 1;
        }

        // -------------------------
        // Build tree
        // -------------------------

        for (int i = size - 1; i >= 1; i--) {

            seg[i] = merge(
                seg[2 * i],
                seg[2 * i + 1]
            );
        }

        // -------------------------
        // Update function
        // -------------------------

        auto update = [&](int index, int value) {

            int pos = size + index;

            // Clear old node
            seg[pos] = Node();

            int rem = value % k;

            seg[pos].empty = false;
            seg[pos].prod = rem;
            seg[pos].cnt[rem] = 1;

            pos /= 2;

            while (pos >= 1) {

                seg[pos] = merge(
                    seg[2 * pos],
                    seg[2 * pos + 1]
                );

                pos /= 2;
            }
        };

        // -------------------------
        // Range query [l, n)
        // -------------------------

        auto query = [&](int l, int r) {

            Node leftResult;
            Node rightResult;

            l += size;
            r += size;

            while (l < r) {

                if (l & 1) {

                    leftResult = merge(
                        leftResult,
                        seg[l]
                    );

                    l++;
                }

                if (r & 1) {

                    --r;

                    rightResult = merge(
                        seg[r],
                        rightResult
                    );
                }

                l /= 2;
                r /= 2;
            }

            return merge(leftResult, rightResult);
        };

        vector<int> answer;

        // -------------------------
        // Process queries
        // -------------------------

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;

            update(index, value);

            // Get nums[start ... n-1]
            Node res = query(start, n);

            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};