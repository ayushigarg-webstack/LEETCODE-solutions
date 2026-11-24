#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        const int maxProduct = 2520 * 10;

        for (int left = 0; left < n; ++left) {
            int product = 1;
            int g = 0;
            int l = 1;

            for (int right = left; right < n; ++right) {
                int x = nums[right];
                product *= x;

                if (product > maxProduct) {
                    break;
                }

                g = gcd(g, x);
                l = l / gcd(l, x) * x;

                if (product == l * g) {
                    answer = max(answer, right - left + 1);
                }
            }
        }

        return answer;
    }
};