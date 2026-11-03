class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        int n= nums.size();

        for(int i = 0; i < nums.size(); i++) {
            moves = moves + (nums[n-1] - nums[i]);
        }

        return moves;
    }
};