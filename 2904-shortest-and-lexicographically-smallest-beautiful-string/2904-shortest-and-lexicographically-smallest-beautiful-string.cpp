class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i = 0;
        int ones = 0;

        string ans = "";

        for (int j = 0; j < s.length(); j++) {

            // Add s[j]
            if (s[j] == '1') {
                ones++;
            }

            // If we have more than k ones,
            // remove from the left
            while (ones > k) {
                if (s[i] == '1') {
                    ones--;
                }
                i++;
            }

            // We have exactly k ones
            if (ones == k) {

                // Remove unnecessary zeroes from left
                while (s[i] == '0') {
                    i++;
                }

                string current = s.substr(i, j - i + 1);

                // First valid answer
                // OR same length but lexicographically smaller
                if (ans == "" ||
                    current.length() < ans.length() ||
                    (current.length() == ans.length() && current < ans)) {

                    ans = current;
                }
            }
        }

        return ans;
    }
};