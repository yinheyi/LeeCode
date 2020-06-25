class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        const size_t rows = matrix.size();
        const size_t columns = matrix.back().size();

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns/ 2; ++j) {
                swap(matrix[i][j], matrix[i][columns - 1 - j]);
            }
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns - 1 - i; ++j) {
                swap(matrix[i][j], matrix[rows - 1 - j][columns - 1 - i];
            }
        }
    }
};
