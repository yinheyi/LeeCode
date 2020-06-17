#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        size_t modifyIndex = -1;
        for (size_t i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                modifyIndex = i - 1;
                break;
            }
        }

        if (modifyIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        size_t minIndex = modifyIndex + 1;
        int minValue = nums[minIndex];
        for (size_t i = minIndex + 1; i < nums.size(); ++i) {
            if (nums[i] > nums[modifyIndex] && nums[i] < minValue) {
                minValue = nums[i];
                minIndex = i;
            }
        }

        swap(nums[modifyIndex], nums[minIndex]);
        sort(nums.begin() + modifyIndex + 1, nums.end());
    }
};

int main()
{
    Solution solver;
    vector<int> a{1, 2, 3};
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    solver.nextPermutation(a);
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;

    return 0; }
