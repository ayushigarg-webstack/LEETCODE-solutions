class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxProfit = 0;
        int minPrice = INT_MAX;
        
        //7 1 5 3 6 4
        for(int i = 0; i < prices.size(); i++)
        {
            minPrice = min(prices[i], minPrice);
            profit = prices[i] - minPrice;
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
};