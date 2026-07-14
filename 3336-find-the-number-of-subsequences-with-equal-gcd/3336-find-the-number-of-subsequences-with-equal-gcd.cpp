class Solution {
public:
    int MOD = 1e9+7;
    int t[201][201][201];
    int solve(vector<int>& nums, int i, int firstGCD, int secondGCD)
    {
        if(i==nums.size())
        {
            if(firstGCD!=0 && secondGCD!=0)
            {
                if(firstGCD == secondGCD)
                    return 1;
                else
                    return 0;
            }
            return 0;
        }
        if(t[i][firstGCD][secondGCD] != -1)
        {
            return t[i][firstGCD][secondGCD];
        }
        int skip = solve(nums, i+1, firstGCD, secondGCD);
        int seq1 = solve(nums, i+1, __gcd(firstGCD, nums[i]), secondGCD);
        int seq2 = solve(nums, i+1, firstGCD, __gcd(secondGCD, nums[i]));
        return t[i][firstGCD][secondGCD] = (0LL+skip+seq1+seq2)%MOD;

    }
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
        
    }
};