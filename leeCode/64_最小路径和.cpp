class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        const int rows = grid.size();
        const int columns = grid.front().size();
        vector<int> bp(columns, 0x7fffffff);
        bp[0] = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) { 
                if (j == 0) {
                    bp[j] += grid[i][j];
                } else {
                    bp[j] = min(bp[j-1], bp[j]) + grid[i][j];
                }
            }
        }
        return bp.back();
    }
};
