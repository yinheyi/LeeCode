class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }

        const int rows = matrix.size();
        const int columns = matrix.back().size();
        const int all = rows * columns;

        int x = rows;
        int y = columns;
        int dx = 0;
        int dy = 1;
        while (result.size() != all) {
            result.push_back(matrix[x % rows][y % columns]);
            matrix[x % rows][y % columns] = 0x80000001;
            if (matrix[(x + dx) % rows][(y + dy) % columns] == 0x80000001) {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
            x += dx;
            y += dy;
        }
        return result;
    }
};
