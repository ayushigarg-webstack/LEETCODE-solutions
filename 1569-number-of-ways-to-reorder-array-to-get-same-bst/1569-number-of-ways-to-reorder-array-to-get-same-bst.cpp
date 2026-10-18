
class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        // One or two elements have only one
        // ordering that preserves the same BST.
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        // Divide elements into left and right subtrees.
        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        // Choose positions for left subtree elements,
        // then arrange both subtrees independently.
        long long ways = comb[n - 1][left.size()];
        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute nCr using Pascal's triangle.
        comb.assign(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] +
                     comb[i - 1][j]) % MOD;
            }
        }

        // Subtract the original ordering.
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
