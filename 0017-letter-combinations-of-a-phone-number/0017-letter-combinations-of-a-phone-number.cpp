class Solution {
public:
    void solve(string digits, unordered_map<char, string> &keypad, vector<string> &ans, int ind, string key)
    {
        if(ind == digits.size())
        {
            ans.push_back(key);
            return;
        }

            
        for(int i = 0; i < keypad[digits[ind]].size(); i++)
        {
            key.push_back(keypad[digits[ind]][i]);
            solve(digits, keypad, ans, ind+1, key);
            key.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        unordered_map<char,string> keypad;
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
        vector<string> ans;
        solve(digits, keypad, ans, 0, "");
        return ans;
    }
};