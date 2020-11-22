#include <algorithm>
#include <vector>

using namespace std;

// 超时了
class Solution1 {
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

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int currentValue = nums[0];
        int vote = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == currentValue) {
                ++vote;
            } else if (--vote == 0) {
                vote = 1;
                currentValue = nums[i];
            }
        }
        return currentValue;
    }
};
