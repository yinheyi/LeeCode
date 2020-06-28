class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }

        const size_t rows = obstacleGrid.size();
        const size_t columns = obstacleGrid.back().size();
        vector<int> bp(columns, 0);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (i == 0 && j == 0) {
                    bp[j] = obstacleGrid[i][j] == 1 ? 0 : 1;
                } else if (i == 0) {
                    bp[j] = obstacleGrid[i][j] == 1 ? 0 : bp[j-1];
                } else if (j == 0) {
                    bp[j] = obstacleGrid[i][j] == 1 ? 0 : bp[j];
                } else {
                    bp[j] = obstacleGrid[i][j] == 1 ? 0 : bp[j - 1] + bp[j];
                }
            }
        }
        return bp.back();
    }
};
