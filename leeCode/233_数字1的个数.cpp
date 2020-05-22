#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n)
    {
        int weishu = GetDigitNum(n);
        int part1 = 0;
        while (weishu - 1 > 0) {
            part1 += GetOneNumof(weishu - 1);
            weishu--;
        }
        int part2 = GetPart(n);
        int sum = part1 + part2;
        return sum;
    }
private:
    int GetDigitNum(int n)
    {
        if (n < 10) {
            return 1;
        } else {
            return 1 + GetDigitNum(n / 10);
        }
    }

    int GetOneNumof(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if ( i == 1) {
                sum += Power(10, n - 1);
            } else {
                sum += 9 * Power(10, n - 2);
            }
        }
        return sum;
    }

    int Power(int base, int pow) {
        int result = 1;
        for (int i = 1; i <= pow; ++i) {
            result *= base;
        }
        return result;
    }

    int GetPart(int n)
    {
        vector<int> numArray;
        while (n) {
            numArray.push_back(n % 10);
            n /= 10;
        }

        int temp = 0;
        for (size_t i = 0; i < numArray.size(); ++i) {
            int result = 1;
            if (numArray[i] == 0) {
                continue;
            }

            temp += result;
        }
        return temp;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution a;
    int result = a.countDigitOne(num);
    cout << result << endl;
    return 0;
}
