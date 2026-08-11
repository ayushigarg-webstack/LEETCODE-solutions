class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int, bool> present;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            present[nums[i]] = true;
        }
        int i = 0;
        prefixSum = nums[0];
        while (i < nums.size() - 1) {
            if (nums[i] + 1 == nums[i + 1]) {
                prefixSum += nums[i + 1];
                i++;
            }
            else {
                break;
            }
        }
        while (present[prefixSum]) {
            prefixSum++;
        }
        return prefixSum;
    }
};