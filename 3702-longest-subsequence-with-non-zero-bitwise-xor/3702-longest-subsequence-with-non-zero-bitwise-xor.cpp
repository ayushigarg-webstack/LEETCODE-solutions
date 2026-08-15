class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xors = 0;
        int n = nums.size();
        int length=n;
        int countZero=0;
        for(int i = 0; i < n; i++)
        {
            xors = xors^nums[i];
            if(nums[i]==0) countZero++;
        }
        if(xors!=0) return n;
        else {
            
            if(countZero==n) return 0;
            return n-1;
        }
    }
};