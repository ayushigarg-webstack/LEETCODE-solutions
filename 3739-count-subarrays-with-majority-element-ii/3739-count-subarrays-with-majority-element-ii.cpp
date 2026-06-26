class Solution {
public:
typedef long long ll;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        map<int, int> mp;
        int cumSum = 0;
        mp[0] = 1;
        ll validLeftPoints = 0;
        ll result = 0;

        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == target)
            {
                validLeftPoints += mp[cumSum];
                cumSum++;
            }
            else {
                cumSum--;
                validLeftPoints -= mp[cumSum];
            }
            mp[cumSum]++;
            result += validLeftPoints;
        }
        return result;
    }
};