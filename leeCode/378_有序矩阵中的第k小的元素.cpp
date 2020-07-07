class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        const int rows = matrix.size();
        const int columns = matrix.back().size();
        int start = matrix.front().front();
        int end = matrix.back().back();
        while (start < end) {
            const int middle = (start + end) >> 1;
            int lessEqual = 0;
            int i = rows - 1;
            int j = 0;
            while (i >= 0 && j < columns) {
                if (matrix[i][j] <= middle) {
                    lessEqual = lessEqual + i + 1;
                    ++j;
                } else {
                    --i;
                }
            }

            if (lessEqual < k) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return start;
    }
};
