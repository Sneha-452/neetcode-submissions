class Solution {
public:
    int maxProfit(vector<int>& prices) {
           int n = prices.size();

    if (n == 0) return 0;

    int i = 0;
    int j = 1;

    int minbuy = prices[0];
    int profit = 0;

    while (j < n) {
        minbuy = min(minbuy, prices[i]);
        profit = max(profit, prices[j] - minbuy);

        i++;
        j++;
    }

    return profit;
    }
};
