#include <iostream>

using namespace std;

int reverse(int x)
{

    bool isNative = x < 0 ? true : false;
    int result = 0;
    while (x) {
        const int quotient = x / 10;
        const int remainder = x % 10;

        if (isNative && result < (0x80000000 - remainder) / 10) {
            return 0;
        } else if (!isNative && result > (0x7fffffff - remainder) / 10) {
            return 0;
        }

        result = result * 10 + remainder;
        x = quotient;
    }
    return result;
}


int main()
{
    int num;
    while (cin >> num) {
        cout << reverse(num) << endl;
    }
    return 0;
}
