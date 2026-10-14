class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string s;
        // s.reserve(num);

        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                s.push_back('9');
                sum -= 9;
            } 
            else {
                s.push_back('0' + sum);
                sum = 0;
            }
        }

        return s;
    }
};