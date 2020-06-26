class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        while (!matrix.empty()) {
            result.insert(result.end(), matrix.front().begin(), matrix.front().end());
            vector<vector<int>> remainer(matrix.begin() + 1, matrix.end());
            RotateMatrix(remainer);
            matrix.swap(remainer);
        }
        return result;
    }

private:
    void RotateMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) {
            return;
        }
        size_t rows = matrix.size();
        size_t columns = matrix.back().size();

        vector<vector<int>> output;
        for (size_t column = columns ; column > 0; --column) {
            vector<int> rowrow;
            for (size_t row = 0; row < rows; ++row) {
                rowrow.push_back(matrix[row][column - 1]);
            }
            output.push_back(move(rowrow));
        }
        matrix.swap(output);
    }
};
