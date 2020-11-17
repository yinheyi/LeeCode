#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size() - 1;

        // 首先去个重复就OK了, 其它不变.
        while (right - left > 1 && nums[left] == nums[right]) {
            ++left;
            --right;
        }

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
