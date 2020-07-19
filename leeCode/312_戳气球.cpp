class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        vector<int> newNums(nums.size() + 2, 1);
        for (size_t i = 0; i < nums.size(); ++i) {
            newNums[i + 1] = nums[i];
        }

        const int L = newNums.size();
        vector<vector<int>> bp(L, vector<int>(L, 0));
        for (int i = L - 1; i >= 0; --i) {
            for (int j = i + 1; j < L; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    bp[i][j] = max(bp[i][j], bp[i][k] + bp[k][j] + newNums[i] * newNums[k] * newNums[j]);
                }
            }
        }
        return bp.front().back();
    }
};
