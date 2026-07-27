class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxNum1 = 0;
        int maxNum2 = 0;
        int iOfNum = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i]>maxNum1)
            {
                maxNum1 = nums[i];
                iOfNum = i;
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(maxNum2<nums[j] && iOfNum!=j)
            {
                maxNum2 = nums[j];
            }
        }
        return ((maxNum1-1)*(maxNum2-1));
    }
};