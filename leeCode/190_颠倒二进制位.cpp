#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit_map(n);
        for (int i = 0; i < 16; ++i) {
            cout << bit_map << endl;
            auto temp = bit_map[i];
            bit_map[i] = bit_map[31 - i];
            bit_map[31 - i] = temp;
            cout << bit_map << endl;
        }
        return bit_map.to_ulong();
    }
};
