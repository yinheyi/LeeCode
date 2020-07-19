#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        srcArray.resize(128, 0);
        constArray.resize(128, 0);
        for (size_t i = 0; i < t.size(); ++i) {
            ++constArray[t[i]];
        }

        size_t begin = 0;
        size_t size = -1;

        const size_t length = s.size();
        const size_t distance = t.size();

        size_t start = 0;
        size_t end = 0;
        size_t curDistance = 0;

        while (end < length) {
            // 更新的距离
            ++srcArray[s[end]];
            if (srcArray[s[end]] <= constArray[s[end]]) {
                ++curDistance;
            }

            while (curDistance == distance) {
                // 更新最短子符串
                if (end - start + 1 < size) {
                    begin = start;
                    size = end - start + 1;
                }

                // 更新距离
                --srcArray[s[start]];
                if (srcArray[s[start]] < constArray[s[start]]) {
                    --curDistance;
                }
                ++start;
            }
            ++end;
        }
        if ( size != -1) {
            return s.substr(begin, size);
        } else {
            return "";
        }
    }
private:
    vector<int> constArray;
    vector<int> srcArray;
};

int main()
{
    Solution solver;
    string a = "a";
    string b = "aa";
    string result =solver.minWindow(a, b);
    cout << result << endl;
    return 0;
}
