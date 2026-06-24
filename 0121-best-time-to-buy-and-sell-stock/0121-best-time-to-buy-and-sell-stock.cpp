class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;

        for(int i=1; i<prices.size(); i++){
            if(min_price > prices[i]) {
                min_price = prices[i];
                continue;
            }
            if(max_profit < prices[i] - min_price) max_profit = prices[i] - min_price;
        }

        return max_profit;
    }
};