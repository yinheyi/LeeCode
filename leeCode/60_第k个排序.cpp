#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        k -= 1;
        string result;
        string str;
        for (int i = 1; i <= n; ++i) {
            str.push_back('0' + i);
        }

        while (str.size() > 1) {
            int factor = factorial(str.size() - 1);
            int index = k / factor;
            k %= factor;
            result.push_back(str[index]);
            str.erase(index, 1);
        }
        result.push_back(str.back());
        return result;
    }

private:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};


int main()
{
    int i, j;
    Solution solver;
    while (cin >> i >> j) {
        string result = solver.getPermutation(i, j);
        cout << result << endl;
    }
    return 0;
}
