class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool> multiples;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % k==0) {
                multiples[nums[i]] = true;
            }
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(multiples[i*k] == false) {
                return i*k;
                break;
            }
        }
        return k*(nums.size()+1);
    }    
};