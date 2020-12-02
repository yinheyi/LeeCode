#include <iostream>
#include <vector>
#include <algorithm>

const int minIntValue = 0x80000000;

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> states(k + 1, vector<int>(2, minIntValue));

        states[0][0] = 0;
        states[0][1] = 0;

        for (size_t i = 0; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                // 更新第j次卖出状态
                if (states[j][0] != minIntValue) {
                    states[j][1] = max(states[j][1], states[j][0] + prices[i]);
                }

                // 更新第j次买入状态
                if (states[j - 1][1] != minIntValue) {
                    states[j][0] = max(states[j][0], states[j - 1][1] - prices[i]);
                }
            }
        }

        int maxValue = minIntValue;
        for (int i = 0; i <= k; ++i) {
            maxValue = max(maxValue, states[i][1]);
        }
        return maxValue;
    }
};
