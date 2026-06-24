class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m(256);
        int p = 0, q = 0;
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                // character already exists in map
                p = max(p, m[s[i]]+1);
                m[s[i]] = i;
            }
            else
            m[s[i]] = i;
            maxLen = max(maxLen, i-p+1);
        }
        return maxLen;
    }
};