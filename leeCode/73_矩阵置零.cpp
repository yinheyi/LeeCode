class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        vector<size_t> rowZero;
        vector<size_t> columnZero;
        const size_t rows = matrix.size();
        const size_t columns = matrix.back().size();
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (matrix[i][j] == 0) {
                    rowZero.push_back(i);
                    columnZero.push_back(j);
                }
            }
        }

        for (size_t i = 0; i < rowZero.size(); ++i) {
            for (size_t j = 0; j < columns; ++j) {
                matrix[rowZero[i]][j] = 0;
            }
        }

        for (size_t i = 0; i < columnZero.size(); ++i) {
            for (size_t j = 0; j < rows; ++j) {
                matrix[j][columnZero[i]] = 0;
            }
        }
    }
};
