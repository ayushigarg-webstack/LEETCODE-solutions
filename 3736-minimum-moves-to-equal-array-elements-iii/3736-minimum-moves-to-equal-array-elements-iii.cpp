class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int moves = 0;
        

        int maximum = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            
            moves = moves + (maximum - nums[i]);
        }

        return moves;
    }
};