#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board.front().empty() || words.empty()) {
            return result;
        }

        rowNum = board.size();
        columnNum = board.front().size();

        for (size_t i = 0; i < words.size(); ++i) {
            if (IsInBoard(board, words[i])) {
                result.push_back(words[i]);
            }
        }
        return result;
    }

private:
    bool IsInBoard(vector<vector<char>>& board, string words) {
        for (size_t i = 0; i < rowNum; ++i) {
            for (size_t j = 0; j < columnNum; ++j) {
                if (IsMatch(board, words, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool IsMatch(vector<vector<char>>& board, string words, size_t index, size_t x, size_t y) {
        if (board[x][y] != words[index]) {
            return false;
        }

        if (words.size() == index + 1) {
            return true;
        }

        char originChar = board[x][y];
        board[x][y] = 0;
        bool result = false;
        if (!result && x > 0) {
            result = IsMatch(board, words, index + 1, x - 1, y);
        }
        if (!result && x < rowNum - 1) {
            result = IsMatch(board, words, index + 1, x + 1, y);
        }
        if (!result && y > 0) {
            result = IsMatch(board, words, index + 1, x, y - 1);
        }
        if (!result && y < columnNum - 1) {
            result = IsMatch(board, words, index + 1, x, y + 1);
        }

        board[x][y] = originChar;
        return result;
    }


    size_t rowNum;
    size_t columnNum;

};
