class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> bp(n, 1);
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                bp[j] += bp[j-1];
            }
        }
        return bp.back();
    }
};
