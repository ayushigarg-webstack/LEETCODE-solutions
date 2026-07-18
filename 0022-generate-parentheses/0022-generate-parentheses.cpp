class Solution {
public:
    void solve(int n, int open, int close, vector<string>& ans, string ps) {
        if (open == n && close == n) {
            ans.push_back(ps);
        }
        if (open - close > 0) {
            solve(n, open, close + 1, ans, ps + ')');
        }
        if (open < n)
            solve(n, open + 1, close, ans, ps + '(');
    }
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        solve(n, 0, 0, ans, ""); 
        return ans;
    }
};