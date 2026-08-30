class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxx=INT_MIN;
        int minn=INT_MAX;
        int minIdx=0;
        int maxIdx=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++) {
            if(minn>nums[i]) {
                minn=nums[i];
                minIdx=i;
            }
            if(maxx<nums[i]) {
                maxx=nums[i];
                maxIdx=i;
            }
        }
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Both from left
        int option1 = right + 1;

        // Both from right
        int option2 = n - left;

        // One from left, one from right
        int option3 = left + 1 + n - right;

        return min({option1, option2, option3});
    }
};