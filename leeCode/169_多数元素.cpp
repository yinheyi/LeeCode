#include <algorithm>
#include <vector>

// 超时了

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while (right - left > 1) {
            int targetIndex = left;
            for (int i = left; i < right; ++i) {
                if (nums[i] < nums[targetIndex]) {
                    swap(nums[i], nums[targetIndex++]);
                }
            }

            if (targetIndex == left) {
            }

            if (targetIndex == nums.size() / 2) {
                return nums[targetIndex];
            } else if (targetIndex < nums.size() / 2) {
                left = (targetIndex == left) ? left + 1 : targetIndex;
            } else {
                right = targetIndex;
            }
        }
        return nums[left];
    }
};
