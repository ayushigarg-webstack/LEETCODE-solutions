class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store knowledge in hash map
        for(auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        for(int i = 0; i < s.length(); i++) {

            // If we encounter '('
            if(s[i] == '(') {

                int j = i + 1;

                // Find closing ')'
                while(s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check if key exists
                if(mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }

                // Move i after ')'
                i = j;
            }
            else {
                // Normal character
                ans += s[i];
            }
        }

        return ans;
    }
};