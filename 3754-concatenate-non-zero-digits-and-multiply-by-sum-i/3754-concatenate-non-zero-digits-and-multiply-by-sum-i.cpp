class Solution {
public:
    long long sumAndMultiply(int n) {
        string temp = to_string(n);
        string x = "";
        for(int i = 0; i < temp.length(); i++)
        {
            if(temp[i]-'0' != 0)
            {
                x += temp[i];
            }
        }
        // long long newNo = x;
        long long sum = 0;
        for(int i = 0; i < x.length(); i++)
        {
            sum = sum + (x[i]-'0');
        }
        if(x.empty()) return 0;
        long long newNo = stoll(x);
        return sum*newNo;

    }
};