class Solution {
public:
    // int solve(vector<int>& nums, vector<int>& dp, int idx) {
    //     if(idx==0) return nums[idx];
    //     if(idx<0) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     //pick
    //     int pick = nums[idx]+solve(nums,dp,idx-2);
    //     //not pick
    //     int notPick = solve(nums,dp,idx-1);
    //     return dp[idx]=max(pick,notPick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++) {
            int take=nums[i];
            if(i>1) take=take+prev2;
            int notTake=0+prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};