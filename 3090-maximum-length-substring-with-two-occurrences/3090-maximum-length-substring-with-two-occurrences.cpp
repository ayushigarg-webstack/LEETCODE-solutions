class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0, j=0;
        unordered_map<int,int> freq;
        int k =2;
        int length=0,maxLength=0;
        while(j<s.length())
        {
            if(freq[s[j]]<2)
            {
                freq[s[j]]++;
                length++;
                j++;
                maxLength=max(maxLength,length);
            }
            else {
                
                freq[s[i]]--;
                i++;
                length--;
            }
        }
        return maxLength;
    }
};