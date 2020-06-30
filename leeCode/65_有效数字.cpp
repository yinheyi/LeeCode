#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        string str = s;
        while (!str.empty()) {
            if (str.front() == ' ') {
                str.erase(str.begin());
                continue;
            }
            if (str.back() == ' ') {
                str.erase(str.end() - 1);
                continue;
            }
            break;
        }

        if (str.empty()) {
            return false;
        }

        set<char> validAlpha{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', 'e', '.'};
        for (size_t i = 0; i < str.size(); ++i) {
            if (validAlpha.count(str[i]) == 0) {
                return false;
            }

            if (str[i] == '-' || str[i] == '+') {
                if (i != 0) {
                    if (str[i-1] != 'e')
                        return false;
                }
                validAlpha.erase('-');
                validAlpha.erase('+');
                bool hasE = validAlpha.count('e') == 1;
                validAlpha.erase('e');
                if (i+1 == str.size() || validAlpha.count(str[i+1]) == 0) {
                    return false;
                }
                if (hasE)
                    validAlpha.insert('e');
            } else if (str[i] == '.') {
                validAlpha.erase('.');
                bool frontDigit = i > 0 && str[i-1] >= '0' && str[i-1] <= '9';
                bool backDigit = i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9';
                if (!frontDigit && !backDigit) {
                    return false;
                }
            } else if (str[i] == 'e') {
                validAlpha.erase('e');
                validAlpha.erase('.');
                if (i == 0) {
                    return false;
                }

                if (validAlpha.count(str.back()) == 0) {
                    return false;
                }

                validAlpha.insert('-');
                validAlpha.insert('+');
            }
        }
        return true;
    }
};


int main()
{
    return 0;
}

