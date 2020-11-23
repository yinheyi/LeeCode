#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int initValue = 0;
        for (char ch : s) {
            initValue = initValue * 26 - 'A' + ch + 1;
        }
        return initValue;
    }
};
