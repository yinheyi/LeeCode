#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    string str("120d");
    int a;
    try {
        a = stoi(str, nullptr, 16);
    } catch (...) {
        cout << a << endl;
    }
        cout << a << endl;
    return 0;
}
