#include <iostream>
#include <vector>

using namespace std;

int fibo(int input)
{
    if (input <= 0) {
        return 0;
    }

    vector<int> table(input + 1);
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= input; ++i) {
        table[i] = table[i-1] + table[i-2];
    }
    return table[input];
}

