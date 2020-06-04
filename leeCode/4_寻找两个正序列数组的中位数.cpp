#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    Solution() : isOdd(false), totalToDelete(0) {}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.empty() && nums2.empty()) {
            return 0.0;
        }

        isOdd = (nums1.size() + nums2.size()) % 2 == 1;
        totalToDelete = (nums1.size() + nums2.size() - 1) / 2;
        array1 = nums1;
        array2 = nums2;

        while (totalToDelete != 0) {
            DeleteValue();
        }

        return GetMedianValue();
    }

private:
    void DeleteValue();
    double GetMedianValue();

    bool isOdd;
    size_t totalToDelete;
    vector<int> array1;
    vector<int> array2;
};

void Solution::DeleteValue()
{
    if (array1.empty()) {
        while (totalToDelete > 0) {
            array2.pop_back();
            --totalToDelete;
        }
        return;
    }

    if (array2.empty()) {
        while (totalToDelete > 0) {
            array1.pop_back();
            --totalToDelete;
        }
        return;
    }

    if (totalToDelete == 1) {
        if (array1.back() > array2.back()) {
            array1.pop_back();
        } else {
            array2.pop_back();
        }
        --totalToDelete;
        return;
    }

    size_t array1NeedTodelete = totalToDelete / 2;
    size_t array2NeedTodelete = totalToDelete - array1NeedTodelete;
    if (array1NeedTodelete > array1.size()) {
        array1NeedTodelete = array1.size();
        array2NeedTodelete = totalToDelete - array1NeedTodelete;
    } else if (array2NeedTodelete > array2.size()) {
        array2NeedTodelete = array2.size();
        array1NeedTodelete = totalToDelete - array2NeedTodelete;
    }

    int array1BoundaryValue = array1[array1.size() - array1NeedTodelete];
    int array2BoundaryValue = array2[array2.size() - array2NeedTodelete];
    if (array1BoundaryValue > array2BoundaryValue) {
        totalToDelete -= array1NeedTodelete;
        while (array1NeedTodelete-- > 0) {
            array1.pop_back();
        }
    } else {
        totalToDelete -= array2NeedTodelete;
        while (array2NeedTodelete-- > 0) {
            array2.pop_back();
        }
    }
}

double Solution::GetMedianValue()
{
    if (isOdd) {
        if (array1.empty()) {
            return array2.back();
        } else if ( array2.empty()) {
            return array1.back();
        } else {
            return array1.back() > array2.back() ? array1.back() : array2.back();
        }
    }

    if (array1.empty()) {
        return (array2.back() + array2[array2.size() -2]) / 2.0;
    } else if (array2.empty()) {
        return (array1.back() + array1[array1.size() -2]) / 2.0;
    } else {
        int num1;
        int num2;
        if (array1.back() > array2.back()) {
            num1 = array1.back();
            array1.pop_back();
        } else {
            num1 = array2.back();
            array2.pop_back();
        }

        if (array1.empty()) {
            num2 = array2.back();
        } else if (array2.empty()) {
            num2 = array1.back();
        } else {
            num2 = array1.back() > array2.back() ? array1.back() : array2.back();
        }
        return (num1 + num2) / 2.0;
    }
}

int main()
{
    Solution solver;
    vector<int> a{1, 4, 7, 9};
    vector<int> b{2, 3, 5, 6, 8, 10};

    printf("%.1lf\n", solver.findMedianSortedArrays(a, b));
    return 0;
}
