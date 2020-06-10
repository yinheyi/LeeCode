#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> romanToInt;
    romanToInt['I'] = 1;
    romanToInt['V'] = 5;
    romanToInt['X'] = 10;
    romanToInt['L'] = 50;
    romanToInt['C'] = 100;
    romanToInt['D'] = 500;
    romanToInt['M'] = 1000;

    string  str;
    while (cin >> str) {
        str.push_back('I');
        int result = 0;
        for (size_t i = 0; i < str.size() - 1; ++i) {
            if (romanToInt[str[i]] >= romanToInt[str[i + 1]]) {
                result += romanToInt[str[i]];
            } else {
                result -= romanToInt[str[i]];
            }
        }
        cout << result << endl;
    }

    return 0;
}
