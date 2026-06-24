class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int l = 0;
        int max1s = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroCount++;
            }
            if(zeroCount > k)
            {
                while(nums[l] != 0)
                {
                    l++;
                }
                l++;
                zeroCount--;
            }
            max1s = max(max1s, i-l+1);
        }
        return max1s;
    }
};