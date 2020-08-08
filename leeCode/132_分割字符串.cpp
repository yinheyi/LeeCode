#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int length = static_cast<int>(s.size());

        // 初始化DP数组
        vector<int> dp(length);
        for (int i = 0; i < length; ++i) {
            dp[i] = i;
        }

        // 中心扩散
        for (int center = 1; center < length; ++center) {
            CenterSpread(s, center - 1, center, dp);
            CenterSpread(s, center, center, dp);
        }
        return dp.back();
    }

private:
    void CenterSpread(const string& str, int centerLeft, int centerRight, vector<int>& dp) {
        if (str[centerLeft] != str[centerRight]) {
            return;
        }

        const int length = static_cast<int>(str.size());
        while (centerLeft >= 0 && centerRight < length && str[centerLeft] == str[centerRight]) {
            --centerLeft;
            ++centerRight;
            if (centerLeft < 0) {
                dp[centerRight - 1] = 0;
            } else {
                dp[centerRight - 1] = min(dp[centerRight - 1], dp[centerLeft] + 1);
            }
        }
    }
};

int main()
{
    string input = "ccaacabacb";
    Solution solver;
    int result = solver.minCut(input);
    cout << result << endl;
    return 0;
}
