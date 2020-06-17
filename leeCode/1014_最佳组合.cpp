#include <algorithm>
#include <iostream>

#define max(x, y) ((x) < (y) ? (y) : (x))
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.size() < 2) {
            return 0;
        }

        maxValue = A[0] + A[1];
        maxiTh = A[0] + 0;
        for (int i = 1; i < A.size(); ++i) {
            maxValue = max(maxValue, maxiTh + A[i] - i);
            maxiTh = max(maxiTh, A[i] + i);
        }
        return maxValue;
    }
};
