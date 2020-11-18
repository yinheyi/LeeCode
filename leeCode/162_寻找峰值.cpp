#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const size_t n = nums.size();
        size_t left = 0;
        size_t right = n - 1;
        while (left + 1 < right) {
            const size_t mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid]  < nums[mid - 1]) {
                right = mid;
            } else if (mid + 1< n  && nums[mid] < nums[mid + 1]) {
                left = mid;
            } else {
                return mid;
            }
        }
        return nums[left] > nums[right] ? left : right;
    }
};
