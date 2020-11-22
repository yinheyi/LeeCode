#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            const int curSum = numbers[left] + numbers[right];
            if (curSum == target) {
                break;
            } else if (curSum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return vector<int>{left + 1, right + 1};
    }
    
};
