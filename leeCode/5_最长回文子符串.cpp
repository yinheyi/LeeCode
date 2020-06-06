#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 中心法
class Solution {
public:
    string longestPalindrome(string s);
    int GetPalindromeLength(const string& str, int& left, int& right);
};

string Solution::longestPalindrome(string s)
{
    int maxLength = 1;
    int left = 0;
    int right = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        int oddLeft = static_cast<int>(i);
        int oddRight = oddLeft;
        int oddLength = GetPalindromeLength(s, oddLeft, oddRight);
        if (oddLength > maxLength) {
            left = oddLeft;
            right = oddRight;
            maxLength = oddLength;
        }

        int evenLeft = static_cast<int>(i);
        int evenRight = evenLeft + 1;
        int evenLength = GetPalindromeLength(s, evenLeft, evenRight);
        if (evenLength > maxLength) {
            left = evenLeft;
            right = evenRight;
            maxLength = evenLength;
        }
    }

    return s.substr(left, right - left + 1);
}

int Solution::GetPalindromeLength(const string& str, int& left, int& right)
{
    if (str[left] != str[right]) {
        return 0;
    }

    const int strLength = static_cast<int>(str.size());
    while (left >= 0 && right < strLength && str[left] == str[right]) {
        --left;
        ++right;
    }

    left++;
    right--;
    return right - left + 1;
}



// 动态规划
class Solution2 {
public:
    string longestPalindrome(string s) {
        const size_t strSize = s.size();
        vector<vector<size_t>> Table(strSize, vector<size_t>(strSize, 0));

        size_t maxLength = 1;
        size_t start = 0;
        size_t end = start;
        for (size_t j = 0; j < strSize; ++j) {
            for (size_t i = 0; i <= j; ++i) {
                if (i == j) {
                    Table[i][j] = 1;
                } else if (j - i == 1) {
                    Table[i][j] = s[i] == s[j] ? 2 : 0;
                } else {
                    Table[i][j] = (s[i] == s[j] && Table[i+1][j-1] != 0) ? Table[i+1][j-1] + 2 : 0;
                }

                if (Table[i][j] > maxLength) {
                    maxLength = Table[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};



int main()
{
    Solution2 solver;
    string a;
    while (cin >> a) {
        cout << solver.longestPalindrome(a) << endl;
    }
    return 0;
}
