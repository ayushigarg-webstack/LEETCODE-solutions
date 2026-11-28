
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        long long minPrice = INT_MAX;
        long long money = budget;
        long long ans = 0;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, (long long)item[1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
        }

        sort(items.begin(), items.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        for (auto& item : items) {
            long long factor = item[0];
            long long price = item[1];

            if (price >= 2 * minPrice)
                break;

            long long freeCopies = cnt[factor] - 1;

            long long buy = min(freeCopies, money / price);

            ans += 2 * buy;
            money -= buy * price;
        }

        ans += money / minPrice;

        return ans;
    }
};
