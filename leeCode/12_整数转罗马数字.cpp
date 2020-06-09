#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    string result;
    vector<int> numbers{1000, 500, 100, 50, 10, 5, 1};
    vector<char> chars{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 0; i < 7; ++i) {
        while (num / numbers[i]) {
            result.push_back(chars[i]);
            num -= numbers[i];
        }
        num %= numbers[i];
    }

    if (result.size() < 4) {
        return result;
    }

    if (result.size() > 4) {
        vector<string> oldStr{"VIIII", "LXXXX", "DCCCC"};
        vector<string> newStr{"IX", "XC", "CM"};

        size_t index = 0;
        string postProcess;
        for (;index <= result.size() - 5; /**/) {
            size_t count = 0;
            for (;count < 3; ++count) {
                if (result.substr(index, 5) == oldStr[count]) {
                    postProcess += newStr[count];
                    index += 5;
                    break;
                }
            }
            if (count == 3) {
                postProcess.push_back(result[index]);
                ++index;
            }
        }
        if (index < result.size()) {
            postProcess += result.substr(index);
        }
        result = postProcess;
    }

    if (result.size() > 3) {
    vector<string> oldStr{"IIII",  "XXXX", "CCCC"};
    vector<string> newStr{"IV", "XL", "CD"};

        size_t index = 0;
        string postProcess;
        for (;index <= result.size() - 4; /**/) {
            size_t count = 0;
            for (;count < 3; ++count) {
                if (result.substr(index, 4) == oldStr[count]) {
                    postProcess += newStr[count];
                    index += 4;
                    break;
                }
            }
            if (count == 3) {
                postProcess.push_back(result[index]);
                ++index;
            }
        }
        if (index < result.size()) {
            postProcess += result.substr(index);
        }
        result = postProcess;
    }
    return result;
}

int main()
{
    int num;
    while (cin >> num) {
        cout << intToRoman(num) << endl;
    }
    return 0;
}
