class Solution {
public:

    struct Interval {
        int l, r, w, idx;
    };

    struct State {
        long long score;
        vector<int> ids;
    };

    // Return the better of two states
    State better(State a, State b) {

        // Higher score is better
        if (a.score != b.score)
            return (a.score > b.score) ? a : b;

        // Same score -> lexicographically smaller indices
        return (a.ids < b.ids) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<Interval> a(n);

        // Store original index
        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by starting point
        sort(a.begin(), a.end(), [](const Interval& x,
                                    const Interval& y) {

            if (x.l != y.l)
                return x.l < y.l;

            if (x.r != y.r)
                return x.r < y.r;

            return x.idx < y.idx;
        });

        // Store all starting points
        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i].l;
        }

        // next[i] = first interval whose starting point
        // is strictly greater than a[i].r
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] =
                upper_bound(
                    starts.begin(),
                    starts.end(),
                    a[i].r
                ) - starts.begin();
        }

        /*
            dp[i][k] =
            best answer using intervals from i onwards,
            when we can still choose at most k intervals.
        */

        vector<vector<State>> dp(n + 1, vector<State>(5));

        // dp[n][k] = {0, {}}
        // Already initialized.

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take this interval
                State skip = dp[i + 1][k];

                // Option 2: Take this interval
                State take = dp[next[i]][k - 1];

                take.score += a[i].w;
                take.ids.push_back(a[i].idx);

                // Required for lexicographical comparison
                sort(take.ids.begin(), take.ids.end());

                // Choose the better option
                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }
};