class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon.front().empty()) {
            return 1;
        }

        const size_t rows = dungeon.size();
        const size_t columns = dungeon.front().size();
        vector<vector<int>> bp(rows, vector<int>(columns, 1));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (i == 0 && j == 0) {
                    if (dungeon[i][j] < 0) {
                        bp[i][j] += -dungeon[i][j];
                    }
                }
            }
        }
    }
};
