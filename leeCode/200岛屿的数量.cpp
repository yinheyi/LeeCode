class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }

        int count = 0;
        const int rowNum = grid.size();
        const int columnNum = grid.front().size();
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < columnNum; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void DFS(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] != '1')
            return;

        int rowNum = grid.size();
        int columnNum = grid.front().size();
        grid[x][y] = '0';

        if (x - 1 >= 0)
            DFS(grid, x - 1, y);
        if (x + 1 < rowNum)
            DFS(grid, x + 1, y);
        if (y - 1 >= 0)
            DFS(grid, x, y - 1);
        if (y + 1 < columnNum)
            DFS(grid, x, y + 1);
    }
};
