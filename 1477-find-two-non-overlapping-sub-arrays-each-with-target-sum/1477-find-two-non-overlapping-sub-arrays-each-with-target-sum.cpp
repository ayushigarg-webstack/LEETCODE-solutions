class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        
        vector<int> dp(n, INT_MAX);
        
        int left = 0;
        int sum = 0;
        
        int ans = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            
            sum += arr[right];
            
            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            // Carry forward the best previous subarray
            if (right > 0) {
                dp[right] = dp[right - 1];
            }
            
            // We found a subarray with sum = target
            if (sum == target) {
                
                int len = right - left + 1;
                
                // Check if there is a non-overlapping
                // valid subarray before this one
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, len + dp[left - 1]);
                }
                
                // Update best single subarray
                dp[right] = min(dp[right], len);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};