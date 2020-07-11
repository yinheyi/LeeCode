#include <vector>

// 非动态规划的做法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        size_t start = 0;
        for (size_t end = 1; end < prices.size(); ++end) {
            const int curProfit = prices[end] - prices[start];
            maxProfit = max(maxProfit, curProfit);
            if (curProfit <= 0) {
                start = end;
            }
        }
        return maxProfit;
    }
};


// 动态规划的做法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> maxProfile(prices.size(), 0);
        int minPrice = prices.front();
        for (size_t i = 1; i < prices.size(); ++i) {
            maxProfile[i] = max(maxProfile[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfile.back();
    }
};
