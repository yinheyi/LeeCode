class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t total = 1 << n;
        vector<bool> generated(total, false);
        size_t curValue = 0;
        result.push_back(curValue);
        generated[curValue] = true;
        while (result.size() < total) {
            for (int i = 0; i < n; ++i) {
                size_t newValue = curValue ^ (1 << i);
                if (!generated[newValue]) {
                    curValue = newValue;
                    result.push_back(curValue);
                    generated[curValue] = true;
                    break;
                }
            }
        }
        return result;
    }
};
