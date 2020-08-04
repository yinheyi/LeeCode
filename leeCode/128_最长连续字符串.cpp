#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (m[nums[i]] != 0) {
                continue;
            }
            int left = m[nums[i] - 1];
            int right =m[nums[i] + 1];
            int curLength = left + right + 1;
            m[nums[i]] = curLength;
            m[nums[i] - left] = curLength;
            m[nums[i] + right] = curLength;
            maxLength = max(maxLength, curLength);
        }
        return maxLength;
    }
};

int main()
{
    Solution solver;
    vector<int> nums{4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    int result = solver.longestConsecutive(nums);
    return 0;
}
