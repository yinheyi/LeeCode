class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) {
            return;
        }
        int rows = board.size();
        int columns = board.front().size();
        // 第0行 和 最后一行
        for (int i = 0; i < columns; ++i) {
            if (board[0][i] == 'O') {
                DFS(board, 0, i, rows, columns);
            }
            if (board[rows-1][i] == 'O') {
                DFS(board, rows - 1, i, rows, columns);
            }
        }

        // 第0列 和 最后一列
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                DFS(board, i, 0, rows, columns);
            }
            if (board[i][columns - 1] == 'O') {
                DFS(board, i, columns - 1, rows, columns);
            }
        }

        // 处理
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void DFS(vector<vector<char>>& board, int startX, int startY, int rows, int columns)
    {
        if (startX < 0 || startY < 0 || startX >= rows || startY >= columns) {
            return;
        }

        if (board[startX][startY] == 'O') {
            board[startX][startY] = '#';
            DFS(board, startX + 1, startY, rows, columns);
            DFS(board, startX - 1, startY, rows, columns);
            DFS(board, startX, startY + 1, rows, columns);
            DFS(board, startX, startY - 1, rows, columns);
        }
    }
};
