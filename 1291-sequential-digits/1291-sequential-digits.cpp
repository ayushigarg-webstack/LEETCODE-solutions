class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string window = "123456789";
        vector<int> ans;
        for (int j = 2; j <= window.size(); j++) 
        {
            for (int i = 0; i <= window.size()-j; i++) 
            {
                int digit = stoi(window.substr(i, j));
                if (digit >= low && digit <= high) 
                {
                    ans.push_back(digit);
                }
            }
        }
        return ans;
    }
};