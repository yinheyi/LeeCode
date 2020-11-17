#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size() - 1;

        while (right - left > 1) {
            size_t middle = left + (right - left) / 2;
            if (nums[middle] > nums[right]) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return min(nums[left], nums[right]);
    }
};
