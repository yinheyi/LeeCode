class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        return binarySearch(nums, 0, nums.size(), target);
    }
private:
    int binarySearch(const vector<int>& nums, size_t start, size_t end, int target)
    {
        if (start  + 1 == end) {
            return nums[start] == target ? start : start + 1;
        }

        size_t middle = (start + end) / 2;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            return binarySearch(nums, start, middle, target);
        } else {
            return binarySearch(nums, middle, end, target);
        }
    }
};
