class Solution {
public:
    int maxDepth(string s) {
        int maxCount = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else if(s[i] == ')')
            {
                count--;
            } 
        }
        return maxCount;
    }
};