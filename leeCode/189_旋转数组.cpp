#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        if (length <= 1) {
            return;
        }
        Reverse(nums, 0, length - 1);
        Reverse(nums, 0, k - 1);
        Reverse(nums, k, length - 1);
    }
private:
    void Reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        RotateRight(nums, 0, length - 1, k);
    }
private:
    void RotateRight(vector<int>& nums, int start, int end, int k) {
        int length = end - start + 1;
        if (length <= 1 || k == 0 || length == k) {
            return;
        }

        if (k <= length / 2) {
            for (int i = 0; i < k; ++i) {
                swap(nums[start + i], nums[end - k + 1 + i]);
            }
            RotateRight(nums, start + k, end, k);
        } else {
            RotateLeft(nums, start, end, length - k);
        }
    }

    void RotateLeft(vector<int>& nums, int start, int end, int k) {
        int length = end - start + 1;
        if (length <= 1 || k == 0 || length == k) {
            return;
        }

        if (k <= length / 2) {
            for (int i = 0; i < k; ++i) {
                swap(nums[start + i], nums[end - k + 1 + i]);
            }
            RotateLeft(nums, start, end - k, k);
        } else {
            RotateRight(nums, start, end, length - k);
        }
    }
};
