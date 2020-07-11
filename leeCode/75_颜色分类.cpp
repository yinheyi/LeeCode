#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }

        const int length = nums.size();
        int left = 0;
        int right = length - 1;
        int cursor = 0;
        while (cursor <= right) {
            if (nums[cursor] == 0) {
                if (cursor == left) {
                    ++cursor;
                    ++left;
                } else {
                    swap(nums[left], nums[cursor]);
                    ++left;
                }
            } else if (nums[cursor] == 2) {
                if (cursor == right) {
                    return;
                } else {
                    swap(nums[right], nums[cursor]);
                    --right;
                }
            } else {
                ++cursor;
            }
        }
    }
};

int main()
{
    Solution solver;
    vector<int> input{2, 0, 2, 1, 1, 0};
    solver.sortColors(input);
    int left = 0;
    return 0;
}
