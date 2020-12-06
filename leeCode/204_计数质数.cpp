
#include <vector>

class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2) {
            return 0;
        }

        vector<bool> array(n, true);
        array[0] = false;
        array[1] = false;
        for (int i = 2; i < n; ++i) {
            if (!array[i]) {
                continue;
            }

            int maxFactor = (n - 1) / i;
            for (int j = 2; j <= maxFactor; ++j) {
                array[j * i] = false;
            }
        }

        int result = 0;
        for (auto i : array) {
            if (i == true) {
                ++result;
            }
        }
        return result;
    }
};
