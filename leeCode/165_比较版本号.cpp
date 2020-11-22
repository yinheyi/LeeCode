#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> strings1;
        vector<string> strings2;
        SplitVersion(version1, strings1);
        SplitVersion(version2, strings2);

        const size_t maxIndex = max(strings1.size(), strings2.size());
        for (size_t i = 0; i < maxIndex; ++i) {
            const string& str1 = i >= strings1.size() ? "" : strings1[i];
            const string& str2 = i >= strings2.size() ? "" : strings2[i];
            int compareResult = CompareSubStr(str1, str2);
            if (compareResult != 0) {
                return compareResult;
            }
        }
        return 0;
    }

private:
    int CompareSubStr(const string& input1, const string& input2) {

        cout << "子字符串1: " << input1 << endl;
        cout << "子字符串2: " << input2 << endl;
        int first = input1.empty() ? 0 : stoi(input1);
        int second = input2.empty() ? 0 : stoi(input2);

        if (first == second) {
            return 0;
        }
        return first > second ? 1 : -1;
    }

    void SplitVersion(const string& version, vector<string>& outputs) {
        outputs.push_back("");
        for (size_t i = 0; i < version.size(); ++i) {
            if (version[i] == '.') {
                outputs.push_back("");
                continue;
            }
            outputs.back().push_back(version[i]);
        }
    }

    string RemoveLeadZero(const string& input) {
        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] != '0') {
                return input.substr(i);
            }
        }
        return "";
    }
};
