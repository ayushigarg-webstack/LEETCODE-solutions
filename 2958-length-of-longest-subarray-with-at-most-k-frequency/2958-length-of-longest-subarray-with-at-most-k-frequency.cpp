class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i=0;
        int length=0;
        int maxLength=0;
        int j=0;
        while(j<nums.size())
        {
            if(freq[nums[j]]<k) {
                length++;
                freq[nums[j]]++;
                maxLength = max(maxLength, length);
                j++;
            }
            else {
                
                length--;
                freq[nums[i]]--;
                i++;
            }
        }
        return maxLength;
    }
};