#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = "#" + s;
        p = "#" + p;

        vector<vector<bool>> table(s.size(), vector<bool>(p.size(), false));
        for (size_t i = 0; i < s.size(); ++i) {
            for (size_t j = 0; j < p.size(); ++j) {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                } else if (i == 0) {
                    table[i][j] = table[i][j-1] && p[j] == '*';
                } else if (j == 0) {
                    table[i][j] = false;
                } else {
                    if (p[j] == '*') {
                        table[i][j] = table[i-1][j] || table[i][j-1];
                    } else {
                        table[i][j] = table[i-1][j-1] && (s[i] == p[j] || p[j] == '?');
                    }
                }
            }
        }
        return table.back().back();
    }
};

int main()
{
    return 0;
}
