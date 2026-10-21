class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end()))
            return 0;
        if(n == 2) return -1;
        char minC = s[0];
        char maxC = s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] < minC) {
                minC = s[i];
            }
            if(s[i] > maxC) {
                maxC = s[i];
            }
        }
        if(minC == s[0] || maxC == s[n-1]) return 1;
        if(minC == s[n-1] && maxC == s[0]) {
            int minCount = count(s.begin(), s.end(), minC);
            int maxCount = count(s.begin(), s.end(), maxC);
            if(minCount == 1 && maxCount == 1) return 3;
        }
        return 2;
    }
};