#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n)
    {
        return solveNQueens(n).size();
    }
    vector<vector<string>> solveNQueens(int n)
    {
        num = n;
        columns.resize(num, false);
        diagonal.resize(2 * num, false);
        _diagonal.resize(2 * num, false);

        DFS(0);
        return outputs;
    }
private:
    void DFS(int row)
    {
        if (row == num) {
            outputs.push_back(current);
        }
        for (int i = 0; i < num; ++i) {
            if (isOK(row, i)) {
                columns[i] = true;
                diagonal[i + row] = true;
                _diagonal[row - i + num] = true;
                current.push_back(GetString(i));

                DFS(row + 1);

                current.pop_back();
                columns[i] = false;
                diagonal[i + row] = false;
                _diagonal[row - i + num] = false;
            }
        }
    }

    bool isOK(int x, int y)
    {
        if (columns[y] || diagonal[x + y] || _diagonal[x - y + num]) {
            return false;
        }
        return true;
    }

    string GetString(int x)
    {
        string res;
        for (int i = 0; i < num; ++i) {
            if (i == x) {
                res.push_back('Q');
            } else {
                res.push_back('.');
            }
        }
        return res;
    }

    int num;
    vector<bool> columns;
    vector<bool> diagonal;
    vector<bool> _diagonal;
    vector<vector<string>> outputs;
    vector<string> current;
};

int main()
{
    return 0;
}
