class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int count = 1, maxCountInc = 1, maxCountDec = 1;
        for(int i= 0; i < n-1; i++) { 
            if(nums[i]<nums[i+1]) {
                count++;
                maxCountInc = max(maxCountInc, count);
            }
            else {
                count = 1;
            }    
        }
        count = 1;
        for(int i= 0; i < n-1; i++) { 
            if(nums[i]>nums[i+1]) 
            {
                count++;
                maxCountDec = max(maxCountDec, count);
            }

            else {
                count = 1;
            }    
        }

        return max(maxCountInc, maxCountDec);
    }
};