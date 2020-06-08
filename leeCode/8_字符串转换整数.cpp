#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int myAtoi(string str)
{
    // 过滤掉前面的所有空格
    size_t notSpace = 0;
    while (notSpace < str.size() && isspace(str[notSpace])) {
        ++notSpace;
    }

    if (notSpace == str.size()) {
        return 0;
    }

    // 过滤掉'+'或'-'.
    bool isNagative = false;
    if (str[notSpace] == '+') {
        ++notSpace;
    } else if (str[notSpace] == '-') {
        isNagative = true;
        ++notSpace;
    }
    if (notSpace == str.size()) {
        return 0;
    }

    // 正式开始转换
    int result = 0;
    while (notSpace != str.size() && isdigit(str[notSpace])) {
        if (isNagative) {
            if (result < ((int)0x80000000 + (str[notSpace] - '0')) / 10) {
                return (int)0x80000000;
            }
            result = result * 10 - (str[notSpace] - '0');
        } else {
            if (result > ((int)0x7fffffff - (str[notSpace] - '0')) / 10) {
                return (int)0x7fffffff;
            }
            result = result * 10 + (str[notSpace] - '0');
        }
        ++notSpace;
    }
    return result;
}

int main()
{
    string str;
    while (getline(cin, str)) {
        cout << myAtoi(str) << endl;
    }

    return 0;
}
