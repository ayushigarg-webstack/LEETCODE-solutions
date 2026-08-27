class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int bestPos = -1;
        int bestChar = -1;

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Before using target[i], check if a larger character
            // is available.
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            // We cannot continue matching target
            if (cnt[x] == 0)
                break;

            cnt[x]--;
        }

        if (bestPos == -1)
            return "";

        // Reconstruct using the rightmost possible position
        // We need the counts corresponding to the prefix target[0..bestPos-1]
        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        string ans = target.substr(0, bestPos);

        // Remove the prefix characters
        for (int i = 0; i < bestPos; i++)
            freq[target[i] - 'a']--;

        // Use the character that makes us greater
        freq[bestChar]--;

        ans += char('a' + bestChar);

        // Everything after this should be smallest possible
        for (int c = 0; c < 26; c++)
            ans += string(freq[c], char('a' + c));

        return ans;
    }
};