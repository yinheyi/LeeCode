#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        size_t maxLength = 1;
        size_t previousLength = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            for (size_t j = 1; j <= previousLength; ++j) {
                if (s[i] == s[i-j]) {
                    previousLength = j - 1;
                    break;
                }
            }
            previousLength = previousLength + 1;
            maxLength = maxLength > previousLength ? maxLength : previousLength;
        }
        return maxLength;
    }
};

int main()
{
    string a;
    cin >> a;
    Solution ab;
    cout << ab.lengthOfLongestSubstring(a) << endl;
    return 0;
}
