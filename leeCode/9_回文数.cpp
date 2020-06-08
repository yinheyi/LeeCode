#include <iostream>


using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    const int old = x;
    int res = 0;
    while (x) {
        if (res > ((int)0x7fffffff - x % 10) / 10) {
            return false;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }

    if (res == old) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int num;
    while (cin >> num) {
        cout << isPalindrome(num) << endl;
    }
    return 0;
}
