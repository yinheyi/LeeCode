#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// 一般方法
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        const int length = nums.size();

        for (int i = length - 1; i >= 0; --i) {
            int curCount = 0;

            const int target = nums[i];
            int start = i + 1;
            int end = length;
            while (start < end - 1) {
                const int middle = (start + end) / 2;
                if (target <= nums[middle]) {
                    end = middle;
                } else {
                    start = middle;
                }
            }

            if (start < length && nums[start] < target) {
                counts[i] = start - i;
            }
            if (counts[i] > 0) {
                memmove(&nums[i], &nums[i+1], sizeof(int) * counts[i]);
                nums[start] = target;
            }
        }
        return counts;
    }
};
*/



// 归并
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> counts(nums.size(), 0);
        vector<int> index(nums.size(), 0);
        for (size_t i = 0; i < index.size(); ++i) {
            index[i] = i;
        }

        MergeSort(nums, counts, 0, nums.size(), index);
        return counts;
    }

    void MergeSort(const vector<int>& nums, vector<int>& counts,
                  int left, int right, vector<int>& index)
    {
        if (left >= right - 1) {
            return;
        }

        const int middle = (left + right) / 2;
        MergeSort(nums, counts, left, middle, index);
        MergeSort(nums, counts, middle, right, index);
        Merge(nums, counts, left, middle, right, index);
    }

    void Merge(const vector<int>& nums, vector<int>& counts,
              int left, int middle, int right, vector<int>& index)
    {
        vector<int> temp;
        int const start = left;
        int const middleEnd = middle;
        int aaa = 0;
        while (left < middleEnd && middle < right) {

            if (nums[index[left]] <= nums[index[middle]]) {
                temp.push_back(index[left]);
                counts[index[left]] += aaa;
                ++left;
            } else {
                temp.push_back(index[middle]);
                ++middle;
                ++aaa;
            }
        }
        if (left < middleEnd) {
            temp.insert(temp.end(), index.begin() + left, index.begin() + middleEnd);
            for (int i = left; i < middleEnd; ++i) {
                counts[index[i]] += aaa;
            }
        }
        if (middle < right) {
            temp.insert(temp.end(), index.begin() + middle, index.begin() + right);
        }
        memcpy(&index[start], &temp[0], sizeof(int) * temp.size());
    }
};


int main()
{
    vector<int> input{1, 0, 2};
    Solution solver;
    vector<int> counts = solver.countSmaller(input);
    for (size_t i = 0; i < counts.size(); ++i) {
        cout << counts[i] << endl;
    }
    return 0;
}
