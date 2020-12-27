#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 第一步：求模式字符串的最长公共前后缀。
void GetPublicPrePostFix(const string& str, vector<int>& output) {
    output.resize(str.size(), 0);
    for (size_t i = 1; i < str.size(); ++i) {
        // 找到那一个可能的最长公共前后缀
        int preFixLength = output[i - 1];
        while (preFixLength != 0 && str[preFixLength] != str[i]) {
            preFixLength = output[output[preFixLength - 1]];
        }

        output[i] = preFixLength + (str[preFixLength] == str[i] ? 1 : 0);
    }
}

// 第二步：在原字符串中查找是否存在模式串
bool hasSubStr(const string& origin, const string& pattern) {

    vector<int> table;
    GetPublicPrePostFix(pattern, table);

    int index = 0;
    for (size_t i = 0; i < origin.size(); ++i) {
        // 找到那个与第i元素相同的下标index, 或者index=0
        while (index > 0 && origin[i] != pattern[index]) {
            index = table[index - 1];
        }

        // 更新index,变成下一轮要对比位置下标。
        if (origin[i] == pattern[index]) {
            index += 1;
        }

        if (index == pattern.size()) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    string shortestPalindrome(string s) {
        string text(s.rbegin(), s.rend());
        vector<int> table;
        GetPublicPrePostFix(s, table);

        int index = 0;
        for (size_t i = 0; i < text.size(); ++i) {
            while (s[index] != text[i] && index > 0) {
                index = table[index - 1];
            }
            if (s[index] == text[i]) {
                ++index;
            }
        }
        return text + s.substr(index);
    }
};

int main() {
    Solution solver;
    while (true) {
        string input;
        cin >> input;
        cout << solver.shortestPalindrome(input) << endl;
    }
    return 0;
}
