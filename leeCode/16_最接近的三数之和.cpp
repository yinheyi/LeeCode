#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    // 非法
    if (nums.size() < 2) {
        return 07fffffff;
    }

    if (nums.size() == 3) {
        return accumulate(nums.begin(), nums.end(), 0);
    }

    int closestValue = accumulate(nums.begin(), nums.begin() + 3, 0);
    for (size_t i = 0; i < target.size() - 2; ++i) {
        size_t startIndex = i + 1;
        size_t endIndex = nums.size() - 1;
        while (startIndex < endIndex) {
            int curSum = nums[i] + nums[startIndex] + nums[endIndex];
            closestValue = abs(closestValue - target) < abs(curSum - target) ? closestValue : curSum;
            if (curSum < target) {
                ++startIndex;
            } else if (curSum == target) {
                return 0;
            } else {
                --endIndex;
            }
        }
    }
    return closestValue;
}
