#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < s) {
            return 0;
        }

        const int length = nums.size();
        int first = 0;
        int second = 0;
        int minLengh = 0x7fffffff;
        int currentSum = 0;
        while (second < length) {
            while (currentSum < s && second < length) {
                currentSum += nums[second++];
            }
            while (currentSum >= s && first < second) {
                currentSum -= nums[first++];
            }
            minLengh = min(minLengh, second - first + 1);
        }
        return minLengh;
    }
};

int main()
{
    Solution solver;
    vector<int> inputs{2, 3, 1, 2, 4, 3};
    cout << solver.minSubArrayLen(7, inputs) << endl;
    return 0;
}
