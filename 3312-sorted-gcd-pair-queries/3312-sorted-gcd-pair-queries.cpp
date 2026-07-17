class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> divisible(mx + 1, 0);

        // count numbers divisible by each d
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                divisible[d] += freq[m];
        }

        vector<long long> exact(mx + 1, 0);

        // inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            long long cnt = divisible[d];
            exact[d] = cnt * (cnt - 1) / 2;

            for (int m = 2 * d; m <= mx; m += d)
                exact[d] -= exact[m];
        }

        vector<long long> pref(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            pref[d] = pref[d - 1] + exact[d];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};