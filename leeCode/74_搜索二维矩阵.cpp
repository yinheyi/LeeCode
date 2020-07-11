class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) {
            return false;
        }

        const size_t rows = matrix.size();
        const size_t columns = matrix.back().size();

        size_t rowStart = 0;
        size_t rowEnd = rows;
        while (rowStart < rowEnd - 1) {
            const size_t middle = (rowStart + rowEnd) >> 1;
            if (matrix[middle][0] <= target) {
                rowStart = middle;
            } else {
                rowEnd = middle;
            }
        }
        if (target < matrix[rowStart][0] || target > matrix[rowStart][columns - 1]) {
            return false;
        }

        size_t columnStart = 0;
        size_t columnEnd = columns;
        while (columnStart < columnEnd - 1) {
            const size_t middle = (columnStart + columnEnd) >> 1;
            if (target < matrix[rowStart][middle]) {
                columnEnd = middle;
            } else if (target > matrix[rowStart][middle]) {
                columnStart = middle;
            } else  {
                return true;
            }
        }
        return matrix[rowStart][columnStart] == target;
    }
};
