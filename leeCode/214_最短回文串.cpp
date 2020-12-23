#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {

    }
};


// KMP算法
// 第一步：求字符串的最长公共前后缀。
void GetPublicPrePostFix(const string& str, vector<int> output) {
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

// 第二步：求模式串的位置
bool hasSubStr(const string& origin, const string& pattern) {

    int index = 0;
    for (size_t i = 0; i < origin.size(); ++i) {
        while (index > 0 && origin[i] != pattern[index]) {
            index = table[index - 1];
        }

        if (origin[i] == pattern[index]) {
            index += 1;
        }

        if (index == pattern) {
            return true;
        }
    }
    return false;
}
