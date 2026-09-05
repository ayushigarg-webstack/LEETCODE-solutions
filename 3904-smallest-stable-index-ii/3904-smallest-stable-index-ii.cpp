class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = min(nums[i], suffix[i+1]);
        }
        int prefixMax=nums[0];
        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            if(prefixMax-suffix[i] <= k) return i;
        }
        return -1;
    }
};