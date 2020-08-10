#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (size_t i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }

        int addition = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            gas[i] += addition;
            addition = max(0, gas[i]);
            gas[i] = min(gas[i], 0);
        }

        size_t start = 0;
        for (size_t i = 0; i < gas.size(); ++i) { 
            if (gas[i] < 0) {
                if (gas[i] + addition < 0) {
                    return -1;
                } else {
                    addition += gas[i];
                    gas[i] = 0;
                    start = i + 1;
                }
            }
        }
        return start;
    }
};

