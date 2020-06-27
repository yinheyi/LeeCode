class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, -1));
        int x = n;
        int y = n;
        int dx = 0;
        int dy = 1;
        int count = 1;
        while (count <= n * n) {
            output[x % n][y % n] = count;
            if (output[(x + dx) % n][(y + dy) % n] != -1) {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
            x += dx;
            y += dy;
            ++count;
        }
        return output;
    }
};
