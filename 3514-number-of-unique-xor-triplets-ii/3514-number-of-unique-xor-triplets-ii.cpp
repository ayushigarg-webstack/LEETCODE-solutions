class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    //     0 1 1 0 -> 6       0 1 1 0 -> 6   0 1 1 0 -> 6
    //     0 1 1 1 -> 7       0 1 1 1 -> 7   0 1 1 1 -> 7
    //     1 0 0 0 -> 8       1 0 0 1 -> 9   1 0 1 0 -> 10
    //    ---------          ---------      ---------
    //     1 0 0 1 -> 9       1 0 0 0 -> 8   1 0 1 1 -> 11
    unordered_set<int> v;
    unordered_set<int> s;
    int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                v.insert(nums[i]^nums[j]);
            }
        }
        for(int pairXor : v)
        {
            for(int &num: nums)
            {
                s.insert(pairXor^num);
            }

        }
        return s.size();
    }
};