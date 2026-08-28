class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        
        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check whether a palindrome can be formed
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available in the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int m = n / 2;

        /*
            Try to match target's left half as much as possible.
        */

        vector<int> used;
        vector<int> rem = halfCnt;

        int matched = 0;

        for (int i = 0; i < m; i++) {

            int x = target[i] - 'a';

            if (rem[x] == 0)
                break;

            used.push_back(x);
            rem[x]--;
            matched++;
        }

        /*
            Case 1:
            We can make the entire left half equal to
            target's left half.

            Construct that palindrome and directly compare
            it with target.
        */

        if (matched == m) {

            string left = "";

            for (int x : used)
                left += char('a' + x);

            string candidate = left;

            if (n % 2)
                candidate += mid;

            string right = left;
            reverse(right.begin(), right.end());

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        /*
            Case 2:
            We need to make the left half larger.

            Try increasing the rightmost possible position.

            IMPORTANT:
            Start from 'matched', not 'matched - 1'.

            If target[i] itself was unavailable, i == matched
            is the first position where we can try a larger char.
        */

        for (int i = matched; i >= 0; i--) {

            // Characters available after keeping prefix [0 ... i-1]
            vector<int> available = halfCnt;

            for (int j = 0; j < i; j++)
                available[used[j]]--;

            int targetChar = target[i] - 'a';

            // Find smallest available character
            // strictly greater than target[i]
            int bigger = -1;

            for (int c = targetChar + 1; c < 26; c++) {

                if (available[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            /*
                Build the left half:

                prefix + bigger + smallest remaining characters
            */

            string left = "";

            // Keep prefix unchanged
            for (int j = 0; j < i; j++)
                left += char('a' + used[j]);

            // Put the smallest possible character > target[i]
            left += char('a' + bigger);
            available[bigger]--;

            // Fill remaining positions as small as possible
            for (int c = 0; c < 26; c++) {

                while (available[c] > 0) {
                    left += char('a' + c);
                    available[c]--;
                }
            }

            /*
                Construct palindrome
            */

            string candidate = left;

            if (n % 2)
                candidate += mid;

            string right = left;
            reverse(right.begin(), right.end());

            candidate += right;

            return candidate;
        }

        return "";
    }
};