class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int max_profit = 0;
        int n = prices.size();
        
        // Loop 1 se start karte hain taaki hum (i) aur (i-1) ko safely compare kar sakein
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - prices[i - 1];
            
            // Agar aaj ka price pichle din se zyada hai, toh profit add kar lo
            if (profit > 0) {
                max_profit += profit;
            }
        }
        
        return max_profit;
    }
};