class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        vector<size_t> days;
        bool hasBought = false;
        for (size_t i = 0; i < prices.size() - 1; ++i) {
            if (hasBought) {
                if (prices[i] > prices[i + 1]) {
                    days.push_back(i);
                    hasBought = false;
                }
            } else {
                if (prices[i] < prices[i + 1]) {
                    days.push_back(i);
                    hasBought = true;
                }
            }
        }

        if (days.size() & 1 == 1) {
            days.push_back(prices.size() - 1);
        }

        int maxProfit = 0;
        for (size_t i = 1; i < days.size(); i = i + 2) {
            maxProfit += (prices[days[i]] - prices[days[i-1]]);
        }
        return maxProfit;
    }
};
