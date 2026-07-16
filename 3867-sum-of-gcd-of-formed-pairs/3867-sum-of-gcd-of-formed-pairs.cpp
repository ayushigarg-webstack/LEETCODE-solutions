class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        vector<int> prefixGcd(nums.size());
        vector<int> pairGcd;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > mx)
            {
                mx = nums[i];
            }
            prefixGcd[i] = __gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0, j = prefixGcd.size()-1;
        long long sum = 0;
        while(i<j)
        {
            sum += (__gcd(prefixGcd[i], prefixGcd[j]));
            i++;
            j--;
        }
        return sum;
    }
};