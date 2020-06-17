#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(findlowerBoundary(nums, target, 0, nums.size()));
            result.push_back(findUpperBoundary(nums, target, 0, nums.size()));
        }
    }
private:
    int findlowerBoundary(vector<int>&nums, int target, int start, int end)
    {
        if (start + 1 == end) {
            if (nums[start] == target) {
                return start;
            }
            if (nums.size() > end && nums[end] == target) {
                return end;
            }
            return -1;
        }

        int middle = (start + end) / 2;
        if (nums[middle] >= target) {
            findlowerBoundary(nums, target, start, middle);
        } else {
            findlowerBoundary(nums, target, middle, end);
        }
    }

    int findUpperBoundary(vector<int>& nums, int target, int start, int end) {
        if (start + 1 == end) {
            if (nums[start] == target) {
                return start;
            }
            if (start - 1 >= 0 && nums[start - 1] == target) {
                return start - 1;
            }
            return -1;
        }

        int middle = (start + end) / 2;
        if (nums[middle] <= target) {
            findUpperBoundary(nums, target, middle, end);
        } else {
            findUpperBoundary(nums, target, start, middle);
        }
    }
};


int main()
{
    return 0;
}

