#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> hold(prices.size(), 0);
        vector<int> notHold(prices.size(), 0);
        hold[0] = -1 * prices[0];

        for (size_t i = 1; i < prices.size(); ++i) {
            if (i > 1) {
                hold[i] = max(hold[i-1], notHold[i-2] - prices[i]);
            } else {
                hold[i] = max(hold[i-1], 0 - prices[i]);
            }
            notHold[i] = max(notHold[i-1], hold[i-1] + prices[i]);
        }
        return notHold.back();
    }
};



int main()
{
    return 0;
}
