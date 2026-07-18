class Solution {
public:
    typedef vector<string> vs;
    vs ans;
    void solve(string& num, int target, int index, string expr, long long value,
               long long prev) {

        if (index == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;

        for (int i = index; i < num.size(); i++) {

            // Skip numbers with leading zeros
            if (i > index && num[index] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');

            string curr = num.substr(index, i - index + 1);

            if (index == 0) {
                // First number (no operator before it)
                solve(num, target, i + 1, curr, cur, cur);
            } else {

                // +
                solve(num, target, i + 1, expr + "+" + curr, value + cur, cur);

                // -
                solve(num, target, i + 1, expr + "-" + curr, value - cur, -cur);

                // *
                solve(num, target, i + 1, expr + "*" + curr, value - prev + prev * cur, prev * cur);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, "", 0, 0);
        return ans;
    }
};