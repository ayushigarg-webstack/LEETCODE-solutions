class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }
        return __gcd(smallest, largest);
    }
};