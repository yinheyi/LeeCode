#include <iostream>

using namespace std;

bool isMatch(string s, string p)
{
    if (s.empty() && p.empty()) {
        return true;
    }
    if (s.empty()) {
        return p.size() >= 2 && p[2] == '*' && isMatch(s, p.substr(2));
    }
    if (p.empty()) {
        return 0;
    }

    if (p.front() == '.') {
        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        } else {
            return isMatch(s.substr(1), p.substr(1));
        }
    } else {
        if (s.front() == p.front()) {
            if (p.size() >= 2 && p[1] == '*') {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            } else {
                return isMatch(s.substr(1), p.substr(1));
            }
        } else {
            if (p.size() >= 2 && p[1] == '*') {
                return isMatch(s, p.substr(2));
            } else {
                return false;
            }
        }
    }
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
