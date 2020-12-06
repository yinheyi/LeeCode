#include <iostream>

using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int old = n;
        if (m == n) {
            return m;
        }

        int count = 0;
        while (n - m > 0) {
            ++count;
            m /= 2;
            n /= 2;
        }
        return (old >> count) << count;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution solver;
    int res = solver.rangeBitwiseAnd(m, n);
    cout << res << endl;
    return 0;
}
