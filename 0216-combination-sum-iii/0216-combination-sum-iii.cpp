class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans,
               int k, int n, int ind, int sum) {
        if (ind == nums.size()) {
            if (k == 0) {
                if (sum == n)
                    ans.push_back(ds);
            }
            return;
        }

        if (k > 0 && nums[ind] + sum <= n) {
            ds.push_back(nums[ind]);
            solve(nums, ds, ans, k - 1, n, ind + 1, sum + nums[ind]);
            ds.pop_back();
        }
        solve(nums, ds, ans, k, n, ind + 1, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        vector<vector<int>> ans;
        solve(nums, ds, ans, k, n, 0, 0);
        return ans;
    }
};