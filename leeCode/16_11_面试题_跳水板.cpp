class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;

        if (k == 0) {
            return result;
        }

        if (shorter == longer) {
            result.push_back(shorter * k);
            return result;
        }

        for (int i = k; i >= 0; --i) {
            result.push_back(i * shorter + (k - i) * longer);
        }
        return result;
    }
};
