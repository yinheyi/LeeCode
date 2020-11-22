#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) {
            return "";
        }
        n = n - 1;
        string str = convertToTitle(n / 26);
        return str.push_back(intToChar(n % 26));
    }

private:
    char intToChar(int n) {
        return 'A' + n;
    }
};
