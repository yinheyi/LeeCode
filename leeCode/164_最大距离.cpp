#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        const int minValue = *min_element(nums.begin(), nums.end());
        const int maxValue = *max_element(nums.begin(), nums.end());
        const int bucketCapacity = GetBucketCapacity(minValue, maxValue, nums.size());
        const int bucketNums = GetBucketNums(minValue, maxValue, bucketCapacity);


        vector<pair<int, int>> buckets(bucketNums, std::make_pair(0x7fffffff, 0x80000000));
        for (size_t i = 0; i < nums.size(); ++i) {
            int index = GetIndex(nums[i], minValue, bucketCapacity);
            buckets[index].first = min(buckets[index].first, nums[i]);
            buckets[index].second = max(buckets[index].second, nums[i]);
        }

        int previous = minValue;
        int maxGap = 0;
        for (size_t i = 0; i < buckets.size(); ++i) {

            if (buckets[i].first == 0x7fffffff) {
                continue;
            }

            maxGap = max(maxGap, (buckets[i].first - previous));
            previous = buckets[i].second;
        }
        return maxGap;
    }

private:
    int GetBucketCapacity(int minValue, int maxValue, int nums) {
        if (maxValue == minValue) {
            return 1;
        }

        int capacity = (maxValue - minValue) / (nums - 1);
        if ((maxValue - minValue) % (nums - 1) != 0) {
            capacity = capacity + 1;
        }
        return capacity;
    }

    int GetIndex(int value, int minValue, int bucketSize) {
       return (value - minValue) / bucketSize;
   }

    int GetBucketNums(int minValue, int maxValue, int bucketCapacity) {
        return (maxValue - minValue) / bucketCapacity + 1;
    }
};
