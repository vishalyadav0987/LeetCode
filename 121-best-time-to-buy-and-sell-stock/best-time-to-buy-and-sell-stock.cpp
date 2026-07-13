class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowPriceStock = prices[0];

        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - lowPriceStock;
            maxProfit = max(profit,maxProfit);
            lowPriceStock = min(lowPriceStock, prices[i]);
        }

        return maxProfit;
    }
};