class Solution {
public:
    void sum(vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans,
             int target, int ind) {
        if (ind == arr.size()) 
        {
            if (target == 0)
                ans.push_back(ds);
            return;    
        }

        // pick same element
        if (arr[ind] <= target) 
        {
            ds.push_back(arr[ind]);
            sum(arr, ds, ans, target - arr[ind], ind);
            ds.pop_back();
        }
        // not pick same element
        sum(arr, ds, ans, target, ind + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sum(candidates, ds, ans, target, 0);
        return ans;
    }
};