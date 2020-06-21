#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p)
{
    // 方便处理空字符串的情况，头部加一个哨兵字符
    s = " " + s;
    p = " " + p;
    vector<vector<bool>> table(s.size(), vector<bool>(p.size(), false));
    table[0][0] = true;

    // 匹配空字符串的情况
    for (size_t j = 2; j < p.size(); ++j) {
        table[0][j] = p[j] == '*' && table[0][j-2];
    }

    for (size_t i = 1; i < s.size(); ++i) {
        for (size_t j = 1; j < p.size(); ++j) {
            if (p[j] != '*') {
                table[i][j] = table[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
            } else {
                table[i][j] = (j >= 2 && table[i][j-2])    // 匹配0个#*
                    || table[i][j-1]                       // 匹配1个#*
                    || table[i-1][j] && (s[i] == p[j-1] && p[j-1] == '*');  // 匹配多个#*
            }
        }
    }
    return table[s.size() - 1][p.size() - 1];
}

int main()
{
    string str1;
    string str2;
    while (cin >> str1 >> str2) {
        cout << isMatch(str1, str2) << endl;
    }
    return 0;
}
