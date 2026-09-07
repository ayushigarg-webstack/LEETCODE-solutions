class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;  // includes empty subsequence
        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long new_dp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = new_dp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};