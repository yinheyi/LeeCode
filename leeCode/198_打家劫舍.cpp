#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int stoleMax = 0;
        int notStoleMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = stoleMax;
            stoleMax = notStoleMax + nums[i];
            notStoleMax = max(notStoleMax, temp);
        }
        return max(stoleMax, notStoleMax);
    }
};
